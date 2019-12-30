package DP;

import java.util.Arrays;
import java.util.Scanner;

public class Increasing_Subsequence_11055 {
	
	static int MAX = 1000;
	static int[] D = new int[MAX];
	static int[] V = new int[MAX];

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		
		D[0] = V[0] = scanner.nextInt();
		
		for(int i=1; i<N; i++) {
			V[i] = scanner.nextInt();
			D[i] = increasing_max(i) + V[i];
		}
		
		Arrays.sort(D);
		System.out.println(D[MAX-1]);
	}
	
	public static int increasing_max(int n) {
		int V_max = 0;
		int idx = -1;
		for(int i=0; i<n; i++) {
			if(V[i]<V[n]) { //자기보다 작은 수이면
				if(V_max < D[i] + V[n]) { //자기 값 더한 수중에 가장 큰 걸 찾는다
					V_max = D[i] + V[n];
					idx = i;
				}
			}
		}

		if(idx == -1)  return 0; //자기보다 작은게 없었던 경우.
		return D[idx];
	}

}
