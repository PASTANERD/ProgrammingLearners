package DP;

import java.util.Scanner;

public class BuyingCard2_16194 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        
        // n개의 카드를 구매
        int n = sc.nextInt();
        int[] p = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            p[i] = sc.nextInt();
        }
 
        int[] d = new int[n + 1];
 
        for (int i = 1; i <= n; i++) {
            // d의 배열 값을 최대로 준다.
            d[i] = 10000 * 1000;
            for (int j = 1; j <= i; j++) {
                if (d[i] > d[i - j] + p[j]) {
                    d[i] = d[i - j] + p[j];
                }
            }
        }
        System.out.println(d[n]);
    }
}

