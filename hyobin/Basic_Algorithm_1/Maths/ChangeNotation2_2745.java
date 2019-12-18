package Maths;
import java.util.Scanner;
//입력 : ZZZZZ 36
//출력 : 60466175 (첫째 줄에 B진법 수 N을 10진법으로 출력한다.)

public class ChangeNotation2_2745 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		String N= scanner.next();
		long B = scanner.nextInt();
		long S = 0;
		
		for(int i=N.length()-1; i>=0 ; i--) {
			
			int n = (int)(N.charAt(i));
			System.out.println(n);
			if( n >= 65 ) n = n-55;
			else n = n-48;
			System.out.println(n);
			System.out.println(Math.pow(B, N.length()-i-1));
			S+= n*(Math.pow(B, N.length()-i-1));
		}
		System.out.println(S);
	}
}
