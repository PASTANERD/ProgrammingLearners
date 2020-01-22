/*
문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 한 칸에서 다른 칸으로 이동하려면, 두 칸이 인접해야 한다. 두 칸이 변을 공유할 때, 인접하다고 한다.

각각의 벽에 대해서 다음을 구해보려고 한다.

벽을 부수고 이동할 수 있는 곳으로 변경한다.
그 위치에서 이동할 수 있는 칸의 개수를 세어본다.
입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다.

출력
맵의 형태로 정답을 출력한다. 원래 빈 칸인 곳은 0을 출력하고, 벽인 곳은 이동할 수 있는 칸의 개수를 10으로 나눈 나머지를 출력한다.

예제 입력 1 
3 3
101
010
101
예제 출력 1 
303
050
303
예제 입력 2 
4 5
11001
00111
01010
10101
예제 출력 2 
46003
00732
06040
50403
 */
package bfs;
import java.util.*;
import java.io.*;
//시간복잡도 NM^2 으로 이렇게 하면 안됨

public class Wall_cracking_4_16946 {

	static int[] xg = {0,0,1,-1};
	static int[] yg = {1,-1,0,0};
	static int[][] map;
	static int[][] ans;
	static boolean[][] check;
	static int N, M;
	
	public static int dfs(int x, int y) {
		int total = 0;
		if(x<0 || y<0 || x>=N || y>=M) return 0;
		if(map[x][y] == 1) return 0 ;
		if(check[x][y]) return 0;
		check[x][y] = true;
		total++;
		for(int i=0; i<4; i++) {
			total += dfs(x+xg[i], y+yg[i]);
		}
		return total%10;
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		ans = new int[N][M];
		check = new boolean[N][M];
		
		for(int i=0; i<N; i++) {
			String s = br.readLine();
			for(int j=0; j<M; j++) {
				map[i][j] = s.charAt(j) - '0';
			}
		}
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(map[i][j]==0) ans[i][j] = 0;
				else {
					map[i][j] = 0;
					check = new boolean[N][M];
					ans[i][j] = dfs(i, j);
					map[i][j] = 1;
				}
			}
		}
		
		print(ans);
	}
	
	static void print(int[][] M) {
		for(int[] P : M) {
			for(int p : P) {
				System.out.print(p);
			}
			System.out.println();
		}
	}

}
