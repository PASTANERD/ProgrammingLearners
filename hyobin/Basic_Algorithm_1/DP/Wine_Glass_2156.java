package DP;

import java.util.Scanner;

public class Wine_Glass_2156 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int[] D = new int[N];
		int[] wine = new int[N];
		
		
		for(int i=0; i<N; i++) {
			wine[i] = scanner.nextInt();
		}
		
		D[0] = wine[0];
		D[1] = wine[0]+wine[1];
		D[2] = MAX(D[1], wine[0]+wine[2], wine[1]+wine[2]);
		
		for(int i=3; i<N; i++) {
			D[i] = MAX(D[i-1], D[i-2] + wine[i], D[i-3]+wine[i-1]+wine[i]);
		}
		
		System.out.println(D[N-1]);

	}
	
	public static int MAX(int a, int b, int c) {
		int max = a;
		if(b> max) max = b;
		if(c > max) max = c;
		return max;
	}

}
