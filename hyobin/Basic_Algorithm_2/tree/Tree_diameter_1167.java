/*
문제
트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 
트리의 지름을 구하는 프로그램을 작성하시오.

입력
트리가 입력으로 주어진다. 
먼저 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고 (2≤V≤100,000)
둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다. 
(정점 번호는 1부터 V까지 매겨져 있다고 생각한다)

먼저 정점 번호가 주어지고, 
이어서 연결된 간선의 정보를 의미하는 정수가 두 개씩 주어지는데, 
하나는 정점번호, 다른 하나는 그 정점까지의 거리이다. 
예를 들어 네 번째 줄의 경우 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고, 
정점 4와는 거리가 3인 간선으로 연결되어 있는 것을 보여준다. 
각 줄의 마지막에는 -1이 입력으로 주어진다. 
주어지는 거리는 모두 10,000 이하의 자연수이다.

출력
첫째 줄에 트리의 지름을 출력한다.

5
1 3 2 -1
2 4 4 -1
3 1 2 4 3 -1
4 2 4 3 3 5 6 -1
5 4 6 -1

11
 */
package tree;
import java.util.*;
import java.io.*;
import print.*;

//dfs.. 모든 노드 .. 
public class Tree_diameter_1167 {
	static ArrayList<Integer>[] edge;
	static int[][] dm;
	static int max=0;
	
	//s : start
	//p : parent
	//m : 지금까지 거리
	static void dfs(int x, int s, int p, int m) {
		int curr_distance = m + dm[x][p];
		if(max < curr_distance) max = curr_distance;
		for(int y : edge[x]) {
			if(y==p) continue;  //tree 라서 check대신 부모만 처리
			dfs(y, s, x, curr_distance);
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = null;
		edge = new ArrayList[N+1];
		dm = new int[N+1][N+1];
		
		for(int i=0; i<=N; i++) edge[i] = new ArrayList<Integer>();
		
		for(int i=1; i<=N; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			while(true) {
				int y = Integer.parseInt(st.nextToken());
				if( y == -1) break;
				edge[x].add(y);
				dm[x][y] =Integer.parseInt(st.nextToken());
			}
		}
		
//		P.print(edge);
//		P.print(dm);
		
		for(int i=1; i<=N; i++) {
			dfs(i,i,i,0);
		}

		
		System.out.print(max);
	}
}
