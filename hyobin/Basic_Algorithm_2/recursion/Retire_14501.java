package recursion;

import java.util.Scanner;


public class Retire_14501 {
	
	public static int[][] schedule;
	public static int[] pay;
	public static int N;
	public static int answer;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		schedule = new int[N+1][2];
		pay = new int[N+1];
		
		for(int i=1; i<=N; i++) {
			schedule[i][0] = scanner.nextInt();
			schedule[i][1] = scanner.nextInt();
		}
		
		go(1, 0);
		System.out.println(answer);
	}
	
	public static void go(int n, int sum) {
		if(n==N+1) {
			if(answer < sum) answer = sum;
			return;
		}
		if(n > N+1) return;

		go(n+schedule[n][0], sum+schedule[n][1]);
		go(n+1, sum);
	}
}
