/*
트리가 주어졌을 때, 올바른 BFS 방문 순서인지 구해보자
입력으로 주어진 BFS 방문 순서가 올바른 순서면 1, 아니면 0을 출력한다.

4
1 2
1 3
2 4
1 2 3 4

1

4
1 2
1 3
2 4
1 2 4 3

0
 */

package graph_hard;
import java.util.*;
import java.io.*;

public class BFS_Special_16940 {	
	static ArrayList<Integer>[] edge;
	static ArrayList<Integer> q = new ArrayList<Integer>();

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		int N = Integer.parseInt(br.readLine());
		edge = new ArrayList[N+1];
		for(int i=1; i<=N; i++) edge[i] = new ArrayList<Integer>();
		
		for(int i=1; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			edge[u].add(v);
			edge[v].add(u);
		}
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			q.add(Integer.parseInt(st.nextToken()));
		}
		 
		while(!q.isEmpty()) {
			int x = q.remove(0);
			for(int i=0; i<edge[x].size(); i++) {
				
			}
		}
		
	}

}
