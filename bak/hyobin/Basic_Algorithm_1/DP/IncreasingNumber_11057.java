package DP;

import java.util.Arrays;
import java.util.Scanner;

public class IncreasingNumber_11057 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		long[][] D = new long[N+1][10];
		int K = 10007;
		int sum = 0;
		
		Arrays.fill(D[1], 1);
		
		for(int i=2; i<=N; i++) {
			for(int j=0; j<10; j++) {
				for(int k=0; k<=j; k++) {
					D[i][j] += D[i-1][k];
				}
				D[i][j] %= K;
			}
		}
		
		for(long i : D[N]) sum += i;
		
		System.out.println(sum%K);
		
	}

}
