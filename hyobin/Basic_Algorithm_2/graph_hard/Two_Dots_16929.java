/*
점 k개 d1, d2, ..., dk로 이루어진 사이클의 정의는 아래와 같다.

모든 k개의 점은 서로 다르다. 
k는 4보다 크거나 같다.
모든 점의 색은 같다.
모든 1 ≤ i ≤ k-1에 대해서, di와 di+1은 인접하다. 또, dk와 d1도 인접해야 한다. 두 점이 인접하다는 것은 각각의 점이 들어있는 칸이 변을 공유한다는 의미이다.
게임판의 상태가 주어졌을 때, 사이클이 존재하는지 아닌지 구해보자.

첫째 줄에 게임판의 크기 N, M이 주어진다. 둘째 줄부터 N개의 줄에 게임판의 상태가 주어진다. 게임판은 모두 점으로 가득차 있고, 
게임판의 상태는 점의 색을 의미한다. 점의 색은 알파벳 대문자 한 글자이다.

사이클이 존재하는 경우에는 "Yes", 없는 경우에는 "No"를 출력한다.

2 ≤ N, M ≤ 50

3 4
AAAA
ABCA
AADA

No

3 4
AAAA
ABCA
AAAA

Yes
 */

package graph_hard;
import java.util.*;
import java.io.*;

public class Two_Dots_16929 {
	static String[][] dots;
	static boolean[][] check;
	static boolean ans = false;
	static int N, M;
	
	public static void dfs(int i, int j,int type, String s) {
		if(i==0 || j==0 || i>N || j>M) return;
//		System.out.print(i + " " + j+ " " + dots[i][j] + " " + s + " ");
		if(dots[i][j].equals(s)) {
			if(check[i][j] == true) {
//				System.out.println("순환 찾음! ");
				ans = true;
				return;
			}
//			System.out.println(" 계속 가자! ");
			check[i][j] = true;
			if(type != 3) dfs(i-1, j, 0, s);
			if(type != 2) dfs(i, j-1, 1, s);
			if(type != 1) dfs(i, j+1, 2, s);
			if(type != 0) dfs(i+1, j, 3, s);
			
		} else {
//			System.out.println(" 아님 ");
			return;
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		dots = new String[N+1][M+1];
		check = new boolean[N+1][M+1];
		
		for(int i=1; i<=N; i++) {
			String s = br.readLine();
			for(int j=0; j<s.length(); j++) {
				dots[i][j+1] = Character.toString(s.charAt(j));
			}
		}
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=M; j++) {
				if(check[i][j] == false) {
					dfs(i, j, -1, dots[i][j]);
				}
			}
		}
		
		if(ans) System.out.println("Yes");
		else System.out.println("No");
		
	}

}
