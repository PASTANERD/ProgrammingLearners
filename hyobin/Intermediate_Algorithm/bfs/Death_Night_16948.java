/*
문제
게임을 좋아하는 큐브러버는 체스에서 사용할 새로운 말 "데스 나이트"를 만들었다. 데스 나이트가 있는 곳이 (r, c)라면, (r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)로 이동할 수 있다.

크기가 N×N인 체스판과 두 칸 (r1, c1), (r2, c2)가 주어진다. 데스 나이트가 (r1, c1)에서 (r2, c2)로 이동하는 최소 이동 횟수를 구해보자. 체스판의 행과 열은 0번부터 시작한다.

데스 나이트는 체스판 밖으로 벗어날 수 없다.

입력
첫째 줄에 체스판의 크기 N(5 ≤ N ≤ 200)이 주어진다. 둘째 줄에 r1, c1, r2, c2가 주어진다.

출력
첫째 줄에 데스 나이트가 (r1, c1)에서 (r2, c2)로 이동하는 최소 이동 횟수를 출력한다. 이동할 수 없는 경우에는 -1을 출력한다.

예제 입력 1 
7
6 6 0 1
예제 출력 1 
4
예제 입력 2 
6
5 1 0 5
예제 출력 2 
-1
예제 입력 3 
7
0 3 4 3
예제 출력 3 
2
 */
package bfs;
import java.util.*;
import java.io.*;

public class Death_Night_16948 {
	static int N;
	static int r1, c1, r2, c2;
	static int[] xg = {-2, -2, 0, 0, 2, 2};
	static int[] yg = {-1, 1, -2, 2, -1, 1};
	static boolean flag = true;
	static boolean[][] check;
	
	static class P{
		int r;
		int c;
		int count;
		
		P(int r, int c, int count){
			this.r = r;
			this.c = c;
			this.count = count;
		}
	}
	
	static void bfs(){
		Queue<P> q = new LinkedList<>();
		q.add(new P(r1, c1, 0));
		while(!q.isEmpty()) {
			P now = q.remove();
			if(now.r <0 || now.c <0 || now.r >= N || now.c >= N)
				continue;
			if(now.r == r2 && now.c == c2) {
				System.out.println(now.count);
				flag = false;
				break;
			}
			if(check[now.r][now.c]) continue;
			check[now.r][now.c] = true;
			for(int i=0; i<6; i++) {
				q.add(new P(now.r+xg[i], now.c+yg[i], now.count+1));
			}
					
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		r1 = sc.nextInt();
		c1 = sc.nextInt();
		r2 = sc.nextInt();
		c2 = sc.nextInt();
		check = new boolean[N][N];
		
		bfs();
		if(flag) System.out.println(-1);
	}

}
