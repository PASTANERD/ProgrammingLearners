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

public class Wall_cracking_4_again_16946 {

	static int[] xg = {0,0,1,-1};
	static int[] yg = {1,-1,0,0};
	static int[][] map;
	static int[][] ans;
	static int[][] count_id;
	static ArrayList<Integer> count = new ArrayList<Integer>();
	static int N, M;
	
	static int dfs(int x, int y, int c) {
		int total = 1;
		if(x<0 || y<0 || x>=N || y>=M) return 0;
		if(map[x][y] == 1) return 0;
		if(count_id[x][y]>0) return 0;
		count_id[x][y] = c;
		for(int i=0; i<4; i++) {
			total += dfs(x+xg[i], y+yg[i], c);
		}
		return total;
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		ans = new int[N][M];
		count_id = new int[N][M];
		
		for(int i=0; i<N; i++) {
			String s = br.readLine();
			for(int j=0; j<M; j++) {
				map[i][j] = s.charAt(j) - '0';
			}
		}
		
		int c = 1;
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(map[i][j]==0 && count_id[i][j]==0) {
					count.add(dfs(i, j, c++));
				}
			}
		}
		
		ArrayList<Integer> see = new ArrayList<>();
		for(int x=0; x<N; x++) {
			for(int y=0; y<M; y++) {
				if(map[x][y]==1) {
					see.clear();
					for(int i=0; i<4; i++) {
						int nx = x + xg[i];
						int ny = y + yg[i];
						if(nx <0 || ny<0 || nx >=N || ny >=M) continue;
						if(map[nx][ny]==1) continue;
						int id = count_id[nx][ny];
						if(see.contains(id)) continue;
						ans[x][y] += (count.get(id-1)%10);
						see.add(id);
					}
					ans[x][y]++;
				}
			}
		}

		print(ans);
	}
	
	static void print(int[][] M) {
		for(int[] P : M) {
			for(int p : P) {
				System.out.print(p%10);
			}
			System.out.println();
		}
	}

}
