package Maths;
import java.util.Scanner;

public class LCM_1934 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		LCM_1934 MyObject = new LCM_1934();
		int T = scanner.nextInt();
		int A,B, GCD;
		for(int i=0; i<T; i++) {
			A = scanner.nextInt();
			B = scanner.nextInt();
			
			GCD = MyObject.GCD(A,B);
			System.out.println(A*B/GCD);
		}
	}
	
	public int GCD(int a, int b) {
		if(b==0) return a;
		return GCD(b, a%b);
	}
}
