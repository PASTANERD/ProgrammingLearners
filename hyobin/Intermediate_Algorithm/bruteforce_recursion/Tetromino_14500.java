/*
문제
폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.

정사각형은 서로 겹치면 안 된다.
도형은 모두 연결되어 있어야 한다.
정사각형의 변끼리 연결되어 있어야 한다. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다.
정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.



아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.

테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.

테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.

입력
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)

둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

출력
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.

예제 입력 1 
5 5
1 2 3 4 5
5 4 3 2 1
2 3 4 5 6
6 5 4 3 2
1 2 1 2 1
예제 출력 1 
19
예제 입력 2 
4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
예제 출력 2 
20
예제 입력 3 
4 10
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1
예제 출력 3 
7
 */
package bruteforce_recursion;
import java.util.*;
import java.io.*;

public class Tetromino_14500 {
	
	static int[][] tm;
	static boolean[][] check;
	static int max = 0;
	static int N, M = 0 ;
	static int[] xg = {1, -1, 0, 0};
	static int[] yg = {0, 0, 1, -1};
	
	public static void go(int x, int y, int sum, int count) {
		if(count == 4) {
			if(max < sum) max = sum;
			return;
		}
		if(x<0 || y<0 || x==N || y==M) return;
		if(check[x][y]) return;
		check[x][y] = true;
		for(int i=0; i<4; i++) {
			go(x+xg[i], y+yg[i], sum+tm[x][y], count+1);
		}
		check[x][y] = false;
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		tm = new int[N][M];
		check = new boolean[N][M];
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				tm[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				go(i, j, 0, 0);
				if ( j+2 < M) {
					int tsum = tm[i][j] + tm[i][j+1] + tm[i][j+2];
					if(i+1 <N) { //ㅜ
						if(tsum + tm[i+1][j+1] > max)
							max = tsum + tm[i+1][j+1];
					}
					if(i > 0) { // ㅗ
						if(tsum + tm[i-1][j+1] > max)
							max = tsum+tm[i-1][j+1];
					}
				}
				if( i+2 < N) {
					int tsum = tm[i][j] + tm[i+1][j] + tm[i+2][j];
					if(j+1 < M) { // ㅏ
						if(tsum + tm[i+1][j+1] > max)
							max =tsum + tm[i+1][j+1];
					}
					if(j>0) { // 
						if( tsum + tm[i+1][j-1] > max )
							max = tsum + tm[i+1][j-1];
					}
				}
			}
		}
		System.out.println(max);
		
	}

}
