package DP;

import java.util.Arrays;
import java.util.Scanner;

public class Decreasing_Subsequence_11722 {
	
	static int MAX = 1000;
	static int[] V = new int[MAX]; //값
	static int[] LSB = new int[MAX]; //N번째를 포함한제일 긴 부분수열의 길이

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		
		for(int i=0; i<N; i++) {
			V[i] = scanner.nextInt();
			LSB[i] = max(i) + 1;
		}
		
		Arrays.sort(LSB);
		if(LSB[MAX-1]==0) LSB[MAX-1] = 1;
		System.out.println(LSB[MAX-1]);
	}
	
	public static int max(int n) {
		if (n==0) return 0;
		int max = 0;
		int max_idx = -1;
		for(int i=0; i<n; i++) {
			if(V[i] > V[n]) { //더 작으면
				if(LSB[i] > max ) { //제일 긴 값인지 확인
					max = LSB[i];
					max_idx = i;
				}
			}
		}
		return max;
	}

}
