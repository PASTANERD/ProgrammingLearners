package DP;

import java.util.Scanner;

public class Plus_123_9095 {

	static int[] D = new int[101];
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		D[0] = 1;
		D[1] = 1;
		D[2] = 2;
		D[3] = 4;

		for(int i=0; i< T; i++) {
			int n = scanner.nextInt();
			System.out.println(topdown(n));
		}
	}
	
	public static int topdown(int n) {
		if(n<=3) return D[n];
		if(D[n] > 0 ) return D[n];
		
		D[n] = topdown(n-1) + topdown(n-2) + topdown(n-3);
		
		return D[n];
	}
}