package DP;

import java.util.*;

public class Bitonic_Sequence_11054 {
	
	static int MAX = 1000;
	static int[] sequence = new int[MAX];
	static int[] Inc = new int[MAX];
	static int[] Dec = new int[MAX];

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		
		for(int i=0; i<N; i++) {
			sequence[i] = scanner.nextInt();
			Inc[i] = max(i) + 1; // i 까지, 가장긴증가수열 count
		}
		
		for(int i=N-1; i>=0; i--) { //i 기준 가장 긴 감소 수열 개수 카운트
			Dec[i] = min(N, i) + 1;
			Inc[i] = Inc[i] + Dec[i] - 1; //두개 더함
		}
		
		Arrays.sort(Inc);
		System.out.println(Inc[MAX-1]);
	}
	
	public static int max(int n) {
		int max = 0;
		for(int i=0; i<n; i++) {
			if(sequence[i] < sequence[n]) { //작으면
				if(max < Inc[i]) max = Inc[i];
			}
		}
		return max;
	}
	
	public static int min(int N, int n) {
		int max = 0;
		for(int i=N-1; i>n; i--) {
			if(sequence[i] < sequence[n]) {
				if(max < Dec[i]) max = Dec[i];
			}
		}
		return max;
	}

}
