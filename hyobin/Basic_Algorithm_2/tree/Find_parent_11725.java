/*
문제
루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

출력
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.

7
1 6
6 3
3 5
4 1
2 4
4 7

4
6
1
3
1
4

12
1 2
1 3
2 4
3 5
3 6
4 7
4 8
5 9
5 10
6 11
6 12

1
1
2
3
3
4
4
5
5
6
6
 */
package tree;
import java.util.*;
import java.io.*;

//인접 리스트 이용해서 그냥 dfs 하면서 parent[] 채움.
public class Find_parent_11725 {
	static ArrayList<Integer>[] edge;
	static int[] parent;
	
	//tree 모양이라 check 필요 없음 ? ㅇ부모쪽으로만 안가면 됨.
	static void dfs(int x, int p) { //x번째 노드, 부모는 p
		parent[x] = p;
		for(int y : edge[x]) {
			if(y==p) continue;
			dfs(y,x);
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = null;
		edge = new ArrayList[N+1];
		parent = new int[N+1];
		
		for(int i=1; i<=N; i++) {
			edge[i] = new ArrayList<Integer>();
		}
		
		for(int i=0; i<N-1; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			edge[a].add(b);
			edge[b].add(a);
		}
		
		dfs(1,0);
		
		for(int i=2; i<=N; i++) 
			System.out.println(parent[i]);
	}
}
