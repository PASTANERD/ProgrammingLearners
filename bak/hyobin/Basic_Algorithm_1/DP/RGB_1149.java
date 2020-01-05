package DP;

import java.util.Arrays;
import java.util.Scanner;

public class RGB_1149 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] C = new int[1000+1][3];
		int[] color = new int[3];
		
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		
		for(int[] C_array : C)
			Arrays.fill(C_array, 1001);
		
		for(int i=0; i<N; i++) {
			color[0] = scanner.nextInt();
			color[1] = scanner.nextInt();
			color[2] = scanner.nextInt();

			if(i==0) {
				//C[0] = color; 이렇게 하니까 call by value 됨ㅠㅠ
				C[0] = Arrays.copyOf(color, color.length);
				continue;
			}
			
			for(int j=0; j<3; j++) 
				C[i][j] = Math.min(C[i-1][g(j-1)], C[i-1][g(j+1)])+color[j];
		}
		
		Arrays.sort(C[N-1]);
		
		System.out.println(C[N-1][0]);
	}
	
	public static int g(int n) {
		if(n==-1) return 2;
		if(n==3) return 0;
		return n;
	}
}
