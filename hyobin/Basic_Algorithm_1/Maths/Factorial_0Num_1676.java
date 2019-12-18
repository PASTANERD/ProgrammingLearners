package Maths;

import java.util.Scanner;

//소인수분해 -- 2와 5의 조합
//5의 개수가 항상 2의 개수보다 적기 때문에 5의 개수만 세어줌
//N! 0의 개수 = N/5 + N/5의제곱 + N/5의세제곱 ...
//입력 - 첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)
//출력 - 첫째 줄에 구한 0의 개수를 출력한다.

public class Factorial_0Num_1676 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int num_0 = 0;
		
		for(int i=5; i<=N; i*=5) {
			num_0 += N/i;
		}
		//System.out.println(Factorial(N));
		System.out.println(num_0);
	}
	
	public static int Factorial(int N) {
		if(N==1 || N==0) return 1;
		return Factorial(N-1)*N;
	}

}
