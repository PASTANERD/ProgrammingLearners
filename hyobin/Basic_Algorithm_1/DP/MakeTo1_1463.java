package DP;

import java.util.Arrays;
import java.util.Scanner;

public class MakeTo1_1463 {
	
	static int[] d;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		d = new int[N+1];
		
		System.out.println(go(N));
	}
	
	public static int go (int n) {
		if (n==1) return 0;
		if (d[n]>0) return d[n];
		d[n] = go(n-1) + 1;
		if(n%2 ==0) {
			int temp = go(n/2) +1;
			if (d[n]>temp) d[n] = temp;
		}
		if(n%3 ==0) {
			int temp = go(n/3) +1;
			if (d[n]>temp) d[n] = temp;
		}
		return d[n];
	}

}
