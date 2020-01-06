/*
 방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.
 
 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. 
 (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. 
 (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.
 
 첫째 줄에 연결 요소의 개수를 출력한다.
 
6 5
1 2
2 5
5 1
3 4
4 6

2

6 8
1 2
2 5
5 1
3 4
4 6
5 4
2 4
2 3

1
 */
package graph;
import java.io.*;
import java.util.*;

public class Connected_Component_11724_A {
	static int[] parent;
	static int[] rank;
	static int findroot(int x) {
		if(x==parent[x]) return x;
		return parent[x] = findroot(parent[x]);
	}
	//x원소와 y원소를 합치는 함수로 y의 Root노드를 x로 한다.
	static void union(int x, int y) {
		if(rank[x] > rank[y]) {
			parent[y] = x;
		}
		else if (rank[x] < rank[y]) {
			parent[x] = y;
		}
		else {
			parent[y] = x;
			rank[x] += 1;
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		// 유니온 파인드를 사용한다.
		// 두개의 값이 들어오면 두개의 부모를 확인하여 작은 값으로 바꿔준다.
		// 모든 과정이 끝나고 1~9 배열에서 있는 값들을 트루로 바꾸고
		// 트루의 개수를 출력한다.
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(str.nextToken());
		int M = Integer.parseInt(str.nextToken());
		
		parent = new int[N+1];
		rank = new int[N+1];
		 
		//Make Set
		for(int i=1; i<=N; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
		
		for(int i=0; i<M; i++) {
			StringTokenizer temp = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(temp.nextToken());
			int v = Integer.parseInt(temp.nextToken());
			if( (u=findroot(u)) != (v=findroot(v))) {
				union(u,v);
			}
		}
		Set<Integer> set = new HashSet<Integer>();
		for(int i=1; i<=N; i++) {
			set.add(findroot(parent[i]));
		}
		System.out.println(set.size());
	}	

}
