/*
 S[i][j]는 A[i]부터 A[j]까지 합이 0보다 크면 +, 0이면 0, 0보다 작으면 -이다. 
 여기서 i는 항상 j보다 작거나 같다. 이렇게 배열을 채우면 배열에는 총 N*(N+1)/2개의 문자가 있다. 
 (+, -, 0 중 하나) 이 S 배열이 주어졌을 때, 규현이가 쓴 N개의 수 A를 구해서 출력하면 된다.

첫째 줄에 수열의 크기 N이 주어진다. N은 10보다 작거나 같은 자연수이다
첫째 줄에 수열의 원소 N개를 빈 칸을 사이에 두고 출력한다. 
답이 여러 가지 일 경우에는 아무거나 출력하면 된다.

4
-+0++++--+

-2 5 -3 1
 */
package recursion;

import java.util.Scanner;

public class Guess_it_1248 {
	
	public static char[][] sign;
	public static int[] num;
	public static int N;
	public static int flag = 0;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		String s = scanner.next();
		sign = new char[N][N];
		num = new int[N];
		
		int idx = 0;
		for(int i=0; i<N; i++) {
			for(int j=i; j<N; j++) 
				sign[i][j] = s.charAt(idx++);
		}
		
		go(0);
	}

	public static boolean go(int index) {
		if(flag==1) return true;
		
		if(index == N) {
			print();
			return true;
		}
		
		if(sign[index][index] == '+') {
			for(int i=1; i<=10; i++) {
				num[index] = i;
				if(ok(index)) go(index+1);
			}
		}
		
		if(sign[index][index] == '-') {
			for(int i=-1; i>=-10; i--) {
				num[index] = i;
				if(ok(index)) go(index+1);
			}
		}
		
		if(sign[index][index] == '0') {
			num[index] = 0;
			if(ok(index)) go(index+1);
		}
		
		return false;
	}
	
	public static boolean ok(int index) {
		if(flag==1) return true;

		int sum = 0;
		for(int i=index; i>=0; i--) {
			sum += num[i];
			if(sign[i][index] == '+' && sum <= 0) return false ;
			if(sign[i][index] == '-' && sum >= 0) return false;
			if(sign[i][index] == '0' && sum != 0) return false;
		}
		return true;
	}
	
	public static void print() {
		if(flag==0) {
			flag = 1;
			for(int n : num) System.out.print(n + " ");
		}
	}
}


