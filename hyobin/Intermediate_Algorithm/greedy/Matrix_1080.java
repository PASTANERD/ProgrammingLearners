/*
문제
0과 1로만 이루어진 행렬 A와 행렬 B가 있다. 이때, 행렬 A를 행렬 B로 바꾸는데 필요한 연산의 횟수의 최솟값을 구하는 프로그램을 작성하시오.

행렬을 변환하는 연산은 어떤 3*3크기의 부분 행렬에 있는 모든 원소를 뒤집는 것이다. (0 -> 1, 1 -> 0)

입력
첫째 줄에 행렬의 크기 N M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 행렬 A가 주어지고, 그 다음줄부터 N개의 줄에는 행렬 B가 주어진다.

출력
첫째 줄에 문제의 정답을 출력한다. 만약 A를 B로 바꿀 수 없다면 -1을 출력한다.

예제 입력 1 
3 4
0000
0010
0000
1001
1011
1001
예제 출력 1 
2
 */
package greedy;
import java.util.*;
import java.io.*;

public class Matrix_1080 {
	
	static int[] xg = {0,0,0,1,1,1,2,2,2};
	static int[] yg = {0,1,2,0,1,2,0,1,2};
	static int[][] A;
	static int[][] B;
	static int N, M;
	
	public static void change_A(int x, int y) {
		for(int i=0; i<9; i++) {
			int nx = x + xg[i];
			int ny = y + yg[i];
			if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
			A[nx][ny] = change(A[nx][ny]);
		}
	}
	
	public static int change(int x) {
		if(x==1) return 0;
		else return 1;
		
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		A = new int[N][M];
		B = new int[N][M];
		int ans = 0;
		
		getMatrix(br, A);
		getMatrix(br, B);
		
		if(N<3 || M<3) {
			for(int i=0; i<N; i++) {
				for(int j=0; j<M; j++) {
					if(A[i][j] != B[i][j]) {
						System.out.println(-1);
						return;
					}
				}
			}
			System.out.println(0);
			return;
		}

		for(int i=0; i<(N-2); i++) {
			for(int j=0; j<(M-2); j++) {
				if(A[i][j] != B[i][j]) {
					change_A(i,j);
					ans++;
				}
			}
			for(int j=0; j<M; j++) {
				if(A[i][j] != B[i][j]) {
//					System.out.println(i + " " + j + A[i][j] + " " + B[i][j]);
					System.out.println(-1);
					return;
				}
			}
		}
		
		for(int i=(N-2); i<N; i++) {
			for(int j=0; j<M; j++) {
				if(A[i][j] != B[i][j]) {
//					System.out.println(i + " " + j + " " + A[i][j] + " " + B[i][j]);
					System.out.println(-1);
					return;
				}
			}
		}
		
		System.out.println(ans);
	}
	
	public static void getMatrix(BufferedReader br, int[][] matrix) throws IOException {
		for(int i=0; i<N; i++) {
			String s = br.readLine();
			for(int j=0; j<M; j++) {
				matrix[i][j] = s.charAt(j) - '0';
			}
		}
	}

	public static void print(int[][] M) {
		for(int[] m : M) {
			for(int i : m) {
				System.out.print(i);
			}
			System.out.println();
		}
		System.out.println();
	}

}
