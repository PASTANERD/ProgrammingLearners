package Maths;
import java.util.Scanner;

public class Factorial_10872 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		
		System.out.println(Factorial(N));
	}
	
	public static int Factorial(int N) {
		if(N==1 || N==0) return 1;
		return Factorial(N-1)*N;
	}
}
