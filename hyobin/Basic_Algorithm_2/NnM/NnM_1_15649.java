package NnM;

import java.util.Scanner;

public class NnM_1_15649 {
	
	public static boolean[] check = new boolean[10];
	public static int[] a = new int[10];

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		
		go( 0 , N , M );
	}
	
	public static void go(int index, int N, int M) {
		if(index == M) {
			for(int i=0; i<M; i++) System.out.print(a[i] + " ");
			System.out.println();
		}
		for(int i=1; i<=N; i++) {
			if(check[i]) continue;
			a[index] = i;
			check[i] = true;
			go(index+1, N, M);
			check[i] = false;
		}
	}

}
