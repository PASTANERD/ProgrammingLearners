package Maths;

import java.util.Scanner;

public class GCD_LCM_2609 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		GCD_LCM_2609 myObject = new GCD_LCM_2609();
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		
		
		//최대공약수 GCD - 유클리드 호제법
		//a%b = r, GCD(a,b) = GCD(b,r), r이 0이면 b가 최대공약수.
		int GCD = myObject.GCD(a,b);
		
		//최소공배수 LCM
		//a*b = GCD*LCM , LCM = a*b/GCD
		int LCM = a*b/GCD;
		System.out.println(GCD + "\n" + LCM);
		
	}
	
	public int GCD(int a,int b) {
		if(b==0) return a;
		else {
			return GCD(b, a%b);
		}
	}
}
