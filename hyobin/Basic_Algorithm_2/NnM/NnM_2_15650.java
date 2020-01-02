package NnM;

import java.util.Scanner;

public class NnM_2_15650 {

	public static int[] number = new int[10];
	public static boolean[] used = new boolean[10];
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		
		go(0, N, M);
	}
	
	public static void go(int index, int N, int M) {
		if(index == M) {
			for(int i=0; i<M; i++) System.out.print(number[i] + " ");
			System.out.println();
			return;
		}
		
		for(int i=1; i<=N; i++) {
			if(used[i]) continue;
			if(index!=0 && i<number[index-1]) continue;     //행렬을 대각선으로 만들기 위해 이거 추가
			number[index] = i;
			used[i] = true;
			go(index+1, N, M);
			used[i] = false;
		}
	}
}
