package DP;

import java.util.Scanner;

public class BuyingCard_11052 {

	//D[i] = P[n] + D[i-n]  
	//n은 1, 2, 3 ... n이고, P[n]은 가격
	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
 
        int[] P = new int[n + 1];
        int[] D = new int[n + 1];
 
        for (int i = 1; i <= n; i++)
            P[i] = scanner.nextInt();
 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                D[i] = Math.max(D[i], D[i - j] + P[j]);
            }
        }
 
        System.out.println(D[n]);
 
        scanner.close();
	}

}
