/*
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 
더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 
탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 
어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. 
V부터 방문된 점을 순서대로 출력하면 된다.

4 5 1
1 2
1 3
1 4
2 4
3 4

1 2 4 3
1 2 3 4
 */
package graph;
import java.util.*;

public class DFS_BFS_1260_EdgeList {
	
	static Edge[] edge;        //엣지 그냥 다 저장 12 15 23
	static int[] cnt;          //앞 수 기준으로 엣지 개수 세기
	static boolean[] check;    // 체크 ~
	static void dfs(int node) {
		check[node] = true;
		System.out.print(node + " ");
		for(int i=cnt[node-1]; i<cnt[node]; i++) {
			int next = edge[i].to;
			if(check[next] == false) {
				dfs(next);
			}
		}
	}
	static void bfs(int start) {
		Queue<Integer> q = new LinkedList<>();
		q.add(start);
		check[start] = true;
		while(!q.isEmpty()) {
			int node = q.remove();
			System.out.print(node + " ");
			for (int i=cnt[node-1]; i<cnt[node]; i++) {
				int next = edge[i].to;
				if(check[next] == false) {
					check[next] = true;
					q.add(next);
				}
			}
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int start = sc.nextInt();
		edge = new Edge[2*m];
		cnt = new int[n+1];
		check = new boolean[n+1];
		for(int i=0; i<m; i++) {
			int from = sc.nextInt();
			int to = sc.nextInt();
			edge[i] = new Edge(from,to);
			edge[m+i] = new Edge(to,from);  //접히기
		}
		m *= 2;
		Arrays.parallelSort(edge);
		for(int i=0; i<m; i++) {
			cnt[edge[i].from] += 1;
		}
		for(int i=1; i<=n; i++) {
			cnt[i] += cnt[i-1];
		}
		
		dfs(start);
		System.out.println();
		check = new boolean[n+1];
		bfs(start);
		System.out.println();
	}
	
	static class Edge implements Comparable<Edge>{
		int from, to;
		Edge(int from, int to){
			this.from = from;
			this.to = to;
		}
		public int compareTo(Edge that) {
			if (this.from < that.from) {
				return -1;
			} else if (this.from == that.from) {
				if(this.to < that.to) return -1;
				else if (this.to == that.to) return 0;
				else return 1;
			} else return 1;
		}
	}

}


