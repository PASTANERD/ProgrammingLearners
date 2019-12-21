package DP;

import java.util.Arrays;
import java.util.Scanner;

public class Zoo_1309 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int sum = 0;
		int k = 9901;
		
		long [][] D = new long [N+1][3];
		
		Arrays.fill(D[1], 1);
		
		for(int i=2; i<=N; i++) {
			D[i][0] = (D[i-1][0] + D[i-1][1] + D[i-1][2]) % k;
			D[i][1] = (D[i-1][0] + D[i-1][2]) % k;
			D[i][2] = (D[i-1][0] + D[i-1][1]) % k;
		}
		
		for(long i : D[N]) sum += i;
		
		//마지막에도 K 로 나눠줘야 함.
		System.out.println(sum % k);
		
	}

}
