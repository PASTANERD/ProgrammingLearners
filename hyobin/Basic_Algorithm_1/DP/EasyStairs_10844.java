package DP;

import java.util.Scanner;

public class EasyStairs_10844 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	    Scanner scanner = new Scanner(System.in);
	    int n = scanner.nextInt();
	    long[][] dp = new long[101][11];
	 
	    // dp[N][L] = dp[N - 1][L - 1] + dp[N - 1][L + 1]
	    // 길이 N, 마지막 숫자가 L일 경우
	 
	    for (int i = 1; i <= 9; i++) {
	        dp[1][i] = 1;
	    }
	 
	    for (int i = 2; i <= n; i++) {
	        dp[i][0] = dp[i - 1][1];
	        for (int j = 1; j <= 9; j++) {
	            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
	        }
	    }
	 
	    long sum = 0;
	    for (int i = 0; i < 10; i++) {
	        sum += dp[n][i];
	    }
	    System.out.println(sum % 1000000000);
	}

}
