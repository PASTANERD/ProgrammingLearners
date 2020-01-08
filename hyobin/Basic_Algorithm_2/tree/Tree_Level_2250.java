/*
이진트리를 다음의 규칙에 따라 행과 열에 번호가 붙어있는 격자 모양의 틀 속에 그리려고 한다. 
이때 다음의 규칙에 따라 그리려고 한다.

이진트리에서 같은 레벨(level)에 있는 노드는 같은 행에 위치한다.
한 열에는 한 노드만 존재한다.
임의의 노드의 왼쪽 부트리(left subtree)에 있는 노드들은 해당 노드보다 왼쪽의 열에 위치하고, 
오른쪽 부트리(right subtree)에 있는 노드들은 해당 노드보다 오른쪽의 열에 위치한다.
노드가 배치된 가장 왼쪽 열과 오른쪽 열 사이엔 아무 노드도 없이 비어있는 열은 없다.
이와 같은 규칙에 따라 이진트리를 그릴 때 각 레벨의 너비는 그 레벨에 할당된 노드 중 
가장 오른쪽에 위치한 노드의 열 번호에서 가장 왼쪽에 위치한 노드의 열 번호를 뺀 값 더하기 1로 정의한다. 
트리의 레벨은 가장 위쪽에 있는 루트 노드가 1이고 아래로 1씩 증가한다.

아래 그림은 어떤 이진트리를 위의 규칙에 따라 그려 본 것이다. 
첫 번째 레벨의 너비는 1, 두 번째 레벨의 너비는 13, 3번째, 4번째 레벨의 너비는 각각 18이고, 
5번째 레벨의 너비는 13이며, 그리고 6번째 레벨의 너비는 12이다.

우리는 주어진 이진트리를 위의 규칙에 따라 그릴 때에 너비가 가장 넓은 레벨과 그 레벨의 너비를 계산하려고 한다. 
위의 그림의 예에서 너비가 가장 넓은 레벨은 3번째와 4번째로 그 너비는 18이다. 
너비가 가장 넓은 레벨이 두 개 이상 있을 때는 번호가 작은 레벨을 답으로 한다. 
그러므로 이 예에 대한 답은 레벨은 3이고, 너비는 18이다.

임의의 이진트리가 입력으로 주어질 때 너비가 가장 넓은 레벨과 그 레벨의 너비를 출력하는 프로그램을 작성하시오

첫째 줄에 노드의 개수를 나타내는 정수 N(1 ≤ N ≤ 10,000)이 주어진다. 
다음 N개의 줄에는 각 줄마다 노드 번호와 해당 노드의 왼쪽 자식 노드와 오른쪽 자식 노드의 번호가 순서대로 주어진다. 
노드들의 번호는 1부터 N까지이며, 자식이 없는 경우에는 자식 노드의 번호에 -1이 주어진다.

첫째 줄에 너비가 가장 넓은 레벨과 그 레벨의 너비를 순서대로 출력한다. 
너비가 가장 넓은 레벨이 두 개 이상 있을 때에는 번호가 작은 레벨을 출력한다.

19
1 2 3
2 4 5
3 6 7
4 8 -1
5 9 10
6 11 12
7 13 -1
8 -1 -1
9 14 15
10 -1 -1
11 16 -1
12 -1 -1
13 17 -1
14 -1 -1
15 18 -1
16 -1 -1
17 -1 19
18 -1 -1
19 -1 -1

3 18
 */
package tree;
import java.util.*;
import java.io.*;

public class Tree_Level_2250 {
	static int[][] tree;
	static int[] col;
	static ArrayList<Integer>[] level;
	static int max = 1,  maxidx = 1, col_level = 1;;
	static int[] parent;
	
	static void inorder(int i, int l) {
		if(i == -1) return;
		int left = tree[i][0];
		int right = tree[i][1];
		level[l].add(i);
		
		inorder(left, l+1);
		col[i] = col_level++;
		inorder(right, l+1);
	}
	
	static void getmax() {
		for(int i=0; i<level.length-1; i++) { //0~N
			if(level[i].size() == 0) return;
			int first = level[i].get(0);
			int last = level[i].get(level[i].size()-1);
			int width = col[last] - col[first] + 1;
			if( max < width ) {
				maxidx = i+1;
				max = width;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		int N = Integer.parseInt(br.readLine());
		tree = new int[N+1][2];
		level = new ArrayList[N];
		col = new int[N+1];
		parent = new int[N+1];
		
		//입력 받기
		for(int i=0; i<N; i++) {
			level[i] = new ArrayList<Integer>();
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			tree[a][0] = b;
			tree[a][1] = c;
			if(b != -1) parent[b] = a;
			if(c != -1) parent[c] = a;
		}
		
		//루트...,,,,,찾아야함... 
		inorder(findroot(N), 0);
		getmax();
		System.out.print(maxidx + " " + max);
	}
	
	public static int findroot(int N) {
		for(int i=1; i<=N; i++) {
			if(parent[i] == 0 ) {
				return i;
			}
		}
		return -1;
	}
}

/*
9
2 -1 -1
1 2 -1
8 -1 -1
4 1 8
3 4 5
6 -1 -1
5 6 7
7 -1 9
9 -1 -1

4 9
 * */
