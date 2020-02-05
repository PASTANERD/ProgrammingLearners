/*
문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.

예제 입력 1 
6 4
0100
1110
1000
0000
0111
0000
예제 출력 1 
15
예제 입력 2 
4 4
0111
1111
1111
1110
예제 출력 2 
-1

 */
package bfs;
import java.util.*;
import java.io.*;

public class Wall_cracking_1_2206 {
	
	static int[][] wall;
	static boolean[][] check;
	static int N, M, ans = 2001;
	static int[] xg = {0,0,1,-1};
	static int[] yg = {1,-1,0,0};
	
	static class Pair {
		int x;
		int y;
		int count;
		boolean crack;
		Pair (int x, int y, int count, boolean crack){
			this.x = x;
			this.y = y;
			this.count = count;
			this.crack = crack;
		}
	}
	
	public static void bfs() {
		Queue<Pair> q = new LinkedList<Pair>();
		q.add(new Pair(1,1,1,false));
		while(!q.isEmpty()) {
			Pair now = q.remove();
			int x = now.x;
			int y = now.y;
			int count = now.count;
			if(x < 1 || y <1 || x>N || y >M) continue;
			if(check[x][y]) continue;
			if(x==N && y==M) {
				if(ans > count) ans = count;
				break;
			}
			check[x][y] = true;
			if(wall[x][y] == 1) {
				if(now.crack) continue;  //벽이고, 부서진 적이 있으면
				else {  //부서진 적이 없으면
					for(int i=0; i<4; i++)
						q.add(new Pair(x+xg[i], y+yg[i], count+1, true)); //부수고 들어가기
				}
			}
			else {
				for(int i=0; i<4; i++) //벽이 아니면 그냥 가기
					q.add(new Pair(x+xg[i], y+yg[i], count+1, now.crack));
			}
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		wall = new int[N+1][M+1];
		check = new boolean[N+1][M+1];
		
		for(int i=1; i<=N; i++) {
			String s = br.readLine();
			for(int j=1; j<=M; j++) {
				wall[i][j] = Integer.parseInt(s.substring(j-1,j));
			}
		}
		
		bfs();	
		
		if(ans==2001) System.out.println(-1);
		else System.out.println(ans);
	}
	
	public static void print() {
		for(int[] A : wall) {
			for(int a : A) {
				System.out.print(a);
			}
			System.out.println();
		}
		System.out.println();
	}

}
