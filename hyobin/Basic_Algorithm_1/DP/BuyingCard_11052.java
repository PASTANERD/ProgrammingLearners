package DP;

import java.util.Scanner;

public class BuyingCard_11052 {

	//D[i] = P[n] + D[i-n]  
	//n은 1, 2, 3 ... n이고, P[n]은 가격
	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
 
        int[] arr = new int[n + 1];
        int[] d = new int[n + 1];
 
        for (int i = 1; i <= n; i++)
            arr[i] = sc.nextInt();
 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                d[i] = Math.max(d[i], d[i - j] + arr[j]);
            }
        }
 
        System.out.println(d[n]);
 
        sc.close();
	}

}
