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
import java.util.*;

public class Connected_Component_11724 {
	static boolean[] check; //max 1000
	static ArrayList<Integer>[] E;
	static Stack node = new Stack();
	static int answer = 0;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		check = new boolean[N+1];
		E = new ArrayList[N+1];
		for(int i=1; i<=N; i++) {
			E[i] = new ArrayList<Integer>();
		}
		
		//input 받기
		for(int i=0; i<M; i++) {
			int u = scanner.nextInt();
			int v = scanner.nextInt();
			E[u].add(v);
			E[v].add(u);
		}
		
		//sorting
		for(int i=1; i<=N; i++) {
			Collections.sort(E[i]);
			node.add(i);
		}
		
		//bfs
		bfs();
		System.out.println(answer);
	}
	
	public static void bfs() {
		Queue<Integer> q = new LinkedList<Integer>();
		while(!node.empty()) {
			answer++;
			int newNode = (int)node.pop();
			q.add(newNode);
			check[newNode] = true;
			while(!q.isEmpty()) {
				int x = q.remove();
				for(int i=0; i<E[x].size(); i++) {  //엣지 개수만큼
					int y = E[x].get(i);
					if(check[y]==true) continue;
					check[y] = true;
					node.removeElement(y);
					q.add(y);
				}
			}
		}
	}
	
	public static void print(Stack stack) {
		System.out.print("stack : ");
		for(Object i : stack) {
			System.out.print(i + " ");
		}
		System.out.println();
	}

}
