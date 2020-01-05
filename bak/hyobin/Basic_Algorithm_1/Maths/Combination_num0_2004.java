package Maths;
import java.util.Scanner;

//조합 nCm -> n! / (n-m)! m!
//팩토리얼은 2의 개수가 5의 개수보다 항상 많기 때문에 5의 개수만 세어줬는데
//조합은 어떻게 될지 모르기 때문에 동시에 2의개수와 5의 개수를 세어줘야 한다.

public class Combination_num0_2004 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		long n = scanner.nextInt();
		long m = scanner.nextInt();
		
		long num2 = 0;
		long num5 = 0;
		
		for(long i=2; i<=n; i*=2) {
			num2 += n/i;
		}
		for(long i=2; i<=(n-m); i*=2) {
			num2 -= (n-m)/i;
		}
		for(long i=2; i<=m; i*=2) {
			num2 -= m/i;
		}
		for(long i=5; i<=n; i*=5) {
			num5 += n/i;
		}
		for(long i=5; i<=(n-m); i*=5) {
			num5 -= (n-m)/i;
		}
		for(long i=5; i<=m; i*=5) {
			num5 -= m/i;
		}
		//System.out.println(Factorial(n)/Factorial(n-m)*Factorial(m));
		System.out.println(Math.min(num5, num2));
	}
}
