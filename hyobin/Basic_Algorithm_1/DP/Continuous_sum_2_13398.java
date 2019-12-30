package DP;

import java.util.Arrays;
import java.util.Scanner;

//여기서 Arrays.copyOf(~ , idx) , idx 만큼만 length가 결정된다!!! 조심!!
//sequence[i] = Arrays.copyOf(sequence[i-1], N);       //i개 복사

public class Continuous_sum_2_13398 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int[] V = new int[N+1];
		int[] sequence = new int[N];
		int max = 0;
		

		sequence[0] = scanner.nextInt();
		System.out.println(sequence[0]);
		
		for(int i=1; i<N; i++) {
			V[i] = scanner.nextInt();
			if(V[i] < 0 && V[i] < max) {                         //제일 작은 음수값
				sequence[i] = Math.max(sequence[i-1]+max, V[i]);
				max = V[i];
			} else {
				sequence[i] = Math.max(sequence[i-1]+V[i], V[i]);
			}
			System.out.println(sequence[i]);
		}
		
		Arrays.sort(sequence);
		System.out.println(sequence[N-1]);
		
	}
}
