/*
문제
N×M 크기의 보드와 4개의 버튼으로 이루어진 게임이 있다. 보드는 1×1크기의 정사각형 칸으로 나누어져 있고, 각각의 칸은 비어있거나, 벽이다. 두 개의 빈 칸에는 동전이 하나씩 놓여져 있고, 두 동전의 위치는 다르다.

버튼은 "왼쪽", "오른쪽", "위", "아래"와 같이 4가지가 있다. 버튼을 누르면 두 동전이 버튼에 쓰여 있는 방향으로 동시에 이동하게 된다.

동전이 이동하려는 칸이 벽이면, 동전은 이동하지 않는다.
동전이 이동하려는 방향에 칸이 없으면 동전은 보드 바깥으로 떨어진다.
그 외의 경우에는 이동하려는 방향으로 한 칸 이동한다.이동하려는 칸에 동전이 있는 경우에도 한 칸 이동한다.
두 동전 중 하나만 보드에서 떨어뜨리기 위해 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 보드의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 20)

둘째 줄부터 N개의 줄에는 보드의 상태가 주어진다.

o: 동전
.: 빈 칸
#: 벽
동전의 개수는 항상 2개이다.

출력
첫째 줄에 두 동전 중 하나만 보드에서 떨어뜨리기 위해 눌러야 하는 버튼의 최소 횟수를 출력한다. 만약, 두 동전을 떨어뜨릴 수 없거나, 버튼을 10번보다 많이 눌러야 한다면, -1을 출력한다.

예제 입력 1 
1 2
oo
예제 출력 1 
1
예제 입력 2 
6 2
.#
.#
.#
o#
o#
##
예제 출력 2 
4
예제 입력 3 
6 2
..
..
..
o#
o#
##
예제 출력 3 
3
예제 입력 4 
5 3
###
.o.
###
.o.
###
예제 출력 4 
-1
예제 입력 5 
5 3
###
.o.
#.#
.o.
###
예제 출력 5 
3
 */
package bruteforce_recursion;
import java.util.*;
import java.io.*;

public class Two_Coins_16197 {
	
	static int[][] board;
	static boolean[][] check1;
	static boolean[][] check2;
	static int N, M;
	static int COUNT = -1;
	static int[] xg = {1, -1, 0, 0};
	static int[] yg = {0, 0, 1, -1};
	
	public static void go(int x1, int y1, int x2, int y2, int count) {
		if(count > 10) return;
		if( (x1 > N || y1 >M || x1==0 || y1==0) && (x2 > N || y2 > M || x2==0 || y2==0)) 
			return;    //"둘다 떨어짐");
		
		if( ( x1 > N || y1 >M || x1==0 || y1==0) || (x2 >N || y2 >M || x2==0 || y2==0)) {
			if(COUNT == -1) COUNT = count;
			else if (count < COUNT) COUNT = count;
			return;  //"한개만 떨어짐 ");
		}
		if(x1 == x2 && y1 == y2)  return; //"둘이 겹쳐짐");
		for(int i=0; i<4; i++) {
			if(board[x1+xg[i]][y1+yg[i]] == 0 && board[x2+xg[i]][y2+yg[i]] == 0)
				go(x1+xg[i], y1+yg[i], x2+xg[i], y2+yg[i], count+1);
			else if (board[x1+xg[i]][y1+yg[i]] == 0)
				go(x1+xg[i], y1+yg[i], x2, y2, count+1);
			else if (board[x2+xg[i]][y2+yg[i]] == 0)
				go(x1, y1, x2+xg[i], y2+yg[i], count+1);
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		int x1 = 0, y1 =0, x2 = 0, y2 = 0, flag = 0;
		board = new int[N+2][M+2];
		check1 = new boolean[N+2][M+2];
		check2 = new boolean[N+2][M+2];
		
		for(int i=1; i<=N; i++) {
			String input =  br.readLine();
			for(int j=1; j<=M; j++) {
				char c = input.charAt(j-1);
				if(c == '.') board[i][j] = 0;
				else if(c == '#') board[i][j] = 1;
				else {
					if(flag==0) {
						x1 = i;
						y1 = j;
						flag = 1;
					} else {
						x2 = i;
						y2 = j;
					}
					board[i][j] = 0;
				}
			}
		}
		
		go(x1, y1, x2, y2, 0);
		System.out.println(COUNT);
	}

}
