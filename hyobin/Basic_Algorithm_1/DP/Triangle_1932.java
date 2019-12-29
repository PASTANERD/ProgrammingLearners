package DP;

import java.util.Arrays;
import java.util.Scanner;

public class Triangle_1932 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int N_MAX = 500;
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int[][] D = new int[N][N];
		
		D[0][0] = scanner.nextInt(); //첫번째 줄
		D[1][0] = D[0][0] + scanner.nextInt();
		D[1][1] = D[0][0] + scanner.nextInt();
		
		for(int i=2; i<N; i++) {
			D[i][0] = D[i-1][0] + scanner.nextInt();
			for(int j=1; j<i; j++) {
				D[i][j] = Math.max(D[i-1][j-1], D[i-1][j]) + scanner.nextInt();
			}
			D[i][i] = D[i-1][i-1] + scanner.nextInt();
		}
		
		Arrays.sort(D[N-1]);
		System.out.println(D[N-1][N-1]);
	}

}
