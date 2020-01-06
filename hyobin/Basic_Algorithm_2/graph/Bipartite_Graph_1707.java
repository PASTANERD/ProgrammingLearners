/*
 그래프의 정점의 집합을 둘로 분할하여, 
 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때, 
 그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.

그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오.

K개의 줄에 걸쳐 입력으로 주어진 그래프가 
이분 그래프이면 YES, 아니면 NO를 순서대로 출력한다.

2
3 2
1 3
2 3
4 4
1 2
2 3
3 4
4 2


YES
NO
 */
package graph;
import java.util.*;
import java.io.*;

public class Bipartite_Graph_1707 {
	static ArrayList<Integer>[] edge;
	static int[] color;
	
	static boolean dfs(int node, int c) {
		color[node] = c;
		for(int next : edge[node]) {
			if(color[next] == 0) {
				if(dfs(next,3-c) == false) {
					return false;
				}
			} 
			else if (color[next] == color[node]) {
				return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int a=0; a<T; a++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int E = Integer.parseInt(st.nextToken());
			edge = new ArrayList[N+1];
			color = new int[N+1];
			for(int i=1; i<=N; i++) 
				edge[i] = new ArrayList<Integer>();

			for (int b=0; b<E; b++) {
				StringTokenizer stn = new StringTokenizer(br.readLine());
				int u = Integer.parseInt(stn.nextToken());
				int v = Integer.parseInt(stn.nextToken());
				edge[u].add(v);
				edge[v].add(u);
			}
			
			for(int b=1; b<=N; b++) {
				Collections.sort(edge[b]);
			}
			
			boolean ok = true;
			//dfs(1,1) 이렇게 해버리면, 분리된 그래프는 탐색 못함
			for(int i=1; i<=N; i++) {
				if(color[i] == 0) {
					if(dfs(i,1) == false) {
						ok = false;
						break;
					}
				}
			}
			
			if(ok) System.out.println("YES");
			else System.out.println("NO");
			
		}
	}
}

/*
1
6 6
1 3
3 2
1 5
2 5
2 4
4 6
*/
