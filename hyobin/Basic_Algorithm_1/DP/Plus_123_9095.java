package DP;

import java.util.Scanner;

public class Plus_123_9095 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		int[] D = new int[12];
		D[0] = 1;
		D[1] = 1;
		D[2] = 2;
		D[3] = 4;
		for(int i=0; i<T; i++) {
			int n = scanner.nextInt();
			System.out.println(D[n-1] + D[n-2] + D[n-3]);
		}
	}

}
