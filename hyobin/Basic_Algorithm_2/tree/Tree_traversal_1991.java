/*
예를 들어 위와 같은 이진 트리가 입력되면,

전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)

첫째 줄에는 이진 트리의 노드의 개수 N(1≤N≤26)이 주어진다.
 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 
 노드의 이름은 A부터 차례대로 영문자 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 
자식 노드가 없는 경우에는 .으로 표현된다.

첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 
각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.

7
A B C
B D .
C E F
E . .
F . G
D . .
G . .

ABDCEFG
DBAECFG
DBEGFCA
 */
package tree;
import java.util.*;
import java.io.*;

public class Tree_traversal_1991 {
	static String[] tree = new String[1000+1];
	
	static void preorder(int i) { //root의 index 번호를 받음
		if(tree[i].equals(".")) return;
		System.out.print(tree[i]);
		preorder(2*i); //왼쪽 노드
		preorder(2*i+1); //오른쪽 노드
	}
	
	static void inorder(int i) { 
		if(tree[i].equals(".")) return;
		inorder(2*i); //왼쪽 노드
		System.out.print(tree[i]);
		inorder(2*i+1); //오른쪽 노드
	}
	
	static void postorder(int i) {
		if(tree[i].equals(".")) return;
		postorder(2*i); //왼쪽 노드
		postorder(2*i+1); //오른쪽 노드
		System.out.print(tree[i]);
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = null;
		
		st = new StringTokenizer(br.readLine());
		tree[1] = st.nextToken();
		tree[2*1] = st.nextToken();
		tree[2*1+1] = st.nextToken();
		
		for(int i=2; i<=N; i++) {
			st = new StringTokenizer(br.readLine());
			String p = st.nextToken();
			int idx = Arrays.asList(tree).indexOf(p);
			tree[2*idx] = st.nextToken();
			tree[2*idx+1] = st.nextToken();
		}
		
		//dfs .. 
		preorder(1);
		System.out.println();
		inorder(1);
		System.out.println();
		postorder(1);
		
	}

}