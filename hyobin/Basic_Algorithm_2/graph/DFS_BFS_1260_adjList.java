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

import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class DFS_BFS_1260_adjList {
	static ArrayList<Integer>[] a;   //인접 리스트
	static boolean[] c;      //체크했나안했나
	
	public static void dfs(int x) {
		if(c[x]==true) return;
		System.out.print(x + " ");
		c[x] = true;
		for(int i=0; i<a[x].size(); i++) {
			int y = a[x].get(i);
			if(c[y]==false) {
				dfs(y);
			}
		}
	}
	
	public static void bfs(int start) {
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(start);
		c[start] = true;
		while(!q.isEmpty()) {
			int x = q.poll();
			System.out.print(x + " ");
			for(int i=0; i<a[x].size(); i++) {
				int y = a[x].get(i);
				if(c[y] == true) continue;
				q.add(y);
				c[y] = true;
			}
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int start = sc.nextInt();
		a = (ArrayList<Integer>[]) new ArrayList[n+1];
		for(int i=1; i<=n; i++) {
			a[i] = new ArrayList<Integer>();
		}
		
		//인접 리스트 만들기
		//a[i] = 2, 3, 4.. -> i와 연결된 모든 node 
		for(int i=0; i<m; i++) {
			int u= sc.nextInt();
			int v = sc.nextInt();
			a[u].add(v);
			a[v].add(u);
		}
		
		
		//각 노드의 인접 리스트 sorting 하기
		for(int i=1; i<=n; i++) {
			Collections.sort(a[i]);
		}
		
		c = new boolean[n+1];
		dfs(start);
		System.out.println();
		
		c = new boolean[n+1];
		bfs(start);
		System.out.println();
	}

}
