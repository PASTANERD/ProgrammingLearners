/*
<그림 1>과 같이 정사각형 모양의 지도가 있다. 
1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 
철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 
단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 
혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다.
 <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 
 지도를 입력하여 단지수를 출력하고, 
 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
 
 첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 
 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.
 
 첫 번째 줄에는 총 단지수를 출력하시오. 
 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
 
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

3
7
8
9
 */
package graph;
import java.util.*;

public class Apartment_2667 {
//	static ArrayList<Integer>[] edge;
	static char[][] edge = new char[27][27];
	static boolean[][] check = new boolean[27][27];
	static int count = 0;
	static int N;
	
	public static int dfs(int i, int j) {
		if (i ==0 || j==0 || i>N || j>N) return count;
		if(check[i][j]) return 0;
		if(edge[i][j] == '0') return 0;
		check[i][j] = true;
		return 1 + dfs(i-1, j) + dfs(i+1, j) + dfs(i, j-1) + dfs(i, j+1);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		N = Integer.parseInt(scanner.nextLine());

		for(int i=1; i<=N; i++) {
			String s = scanner.nextLine();
			for(int idx=0; idx<s.length(); idx++) {
				edge[i][idx+1] = s.charAt(idx);
			}
		}
		
		ArrayList<Integer> answer = new ArrayList<Integer>();
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				if(check[i][j] == false && edge[i][j]=='1') {
					count = 0;
					answer.add(dfs(i, j));
				}
			}
		}
		
		Collections.sort(answer);
		System.out.println(answer.size());
		for(Integer i : answer)
			System.out.println(i);
	}

}
