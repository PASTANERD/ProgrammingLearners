/*
지하철 2호선에는 51개의 역이 있고, 역과 역 사이를 연결하는 구간이 51개 있다. 즉, 정점이 51개이고, 양방향 간선이 51개인 그래프로 나타낼 수 있다. 
2호선은 순환선 1개와 2개의 지선으로 이루어져 있다. 한 역에서 출발해서 계속 가면 다시 출발한 역으로 돌아올 수 있는 노선을 순환선이라고 한다. 
지선은 순환선에 속하는 한 역에서 시작하는 트리 형태의 노선이다.

두 역(정점) 사이의 거리는 지나야 하는 구간(간선)의 개수이다.
역 A와 순환선 사이의 거리는 A와 순환선에 속하는 역 사이의 거리 중 최솟값이다.

지하철 2호선과 같은 형태의 노선도가 주어졌을 때, 각 역과 순환선 사이의 거리를 구해보자.

첫째 줄에 역의 개수 N(3 ≤ N ≤ 3,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 역과 역을 연결하는 구간의 정보가 주어진다. 
같은 구간이 여러 번 주어지는 경우는 없고, 역은 1번부터 N번까지 번호가 매겨져 있다. 
임의의 두 역 사이에 경로가 항상 존재하는 노선만 입력으로 주어진다.
 
총 N개의 정수를 출력한다. 1번 역과 순환선 사이의 거리, 2번 역과 순환선 사이의 거리, ..., 
N번 역과 순환선 사이의 거리를 공백으로 구분해 출력한다.

6
1 2
3 4
6 4
2 3
1 3
3 5

0 0 0 1 1 2

51
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 16
16 17
17 18
18 19
19 20
20 21
21 22
22 23
23 24
24 25
25 26
26 27
27 28
28 29
29 30
30 31
31 32
32 33
33 34
34 35
35 36
36 37
37 38
38 39
39 40
40 41
41 42
42 43
43 1
11 44
44 45
45 46
46 47
34 48
48 49
49 50
50 51

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 2 3 4 1 2 3 4
 */
package graph_hard;
import java.util.*;
import java.io.*;

public class Subway_16947 {
	static ArrayList<Integer>[] edge;
	static int[] check;
	static boolean[] check2;
	static int[] answer;
	static ArrayList<Integer> cycles = new ArrayList<Integer>();
	
	/*
	 * check[x] 의 값은 0, 1, 2.
	 * 0 = 아직 가지 않은 것, 1 = 지나온 것(스택에있음), 2 = cycle 인 것
	 * 
	 * (int x, int p)
	 * 이미 방문 했던 곳을 다시 방문해서 cycle을 알아내야 하기 때문에
	 * check= 0/1로 판단하지 않는다. 하지만 1->2 로 왔다면 2->1로 돌아가지 않아야 하기 때문에
	 * 부모를 함께 줘서 continue 하도록 한다.
	 * 
	 * 부모 이외에 다 dfs로 깊이 들어가면서,
	 * 이미 왔던 곳(stack에 있는 것 = check[x]=1 )을 탐색한다.
	 * 
	 * check[x]를 발견했다면 그곳이 바로 시작점! (발견 x이면 -1 return)
	 * 그 x를 찾아서 return x 를 한다.
	 * 
	 * x를 찾았다면, 그 부모는 cycle에 포함되지 않는다.
	 * 그러므로 부모에게 return 하는 값은, -2 return
	 * -2 부터는 다 -2 이다.
	 * 
	 * 결과 check[] 는, cycle인 index 부분만 2가된다.
	 * 
	 * 6
1 2
3 4
6 4
2 3
1 3
3 5
( 1 , 1 )
( 2 , 1 )
( 3 , 2 )
( 4 , 3 )
( 6 , 4 )
( 1 , 3 )
check
0 2 2 2 1 0 1 
	 */
	public static int dfs_cycle(int x, int p) {
		if(check[x] == 1) return x;
		check[x] = 1;
		for(int y : edge[x]) {
			if(y==p) continue;
			int cycle = dfs_cycle(y, x);
			if(cycle == -2) return -2;
			if(cycle > 0) {
				check[x] = 2;
				cycles.add(x);
				if(x==cycle) return -2;
				else return cycle;
			}
		}
		return -1;
	}
	
	public static void dfs(int x, int count) {
		if(check[x]==2 && count!=0) return;
		if(check2[x]==true) return;
		answer[x] = count;
		check2[x] = true;
		for(int y: edge[x]) {
			dfs(y,count+1);
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		int N = Integer.parseInt(br.readLine());
		check = new int[N+1];
		edge = new ArrayList[N+1];
		for(int i=1; i<=N; i++) {
			edge[i] = new ArrayList<Integer>();
		}
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			edge[u].add(v);
			edge[v].add(u);
		}
		
		dfs_cycle(1,1);
		
		check2 = new boolean[N+1];
		answer = new int[N+1];
		for(int start : cycles) dfs(start, 0);
		for (int i=1; i<=N; i++) 
			System.out.print(answer[i] + " ");
	}
	
	public static void print(int[] map, String s) {
		System.out.println(s);
		for (int m : map) 
			System.out.print(m + " ");
		System.out.println("\n");
	}
	
	public static void print(boolean[] map, String s) {
		System.out.println(s);
		for (boolean m : map) 
			System.out.print(m + " ");
		System.out.println("\n");
	}
	
	public static void print(ArrayList<Integer> map, String s) {
		System.out.println(s);
		for (int m : map) 
			System.out.print(m + " ");
		System.out.println("\n");
	}
	
	

}
