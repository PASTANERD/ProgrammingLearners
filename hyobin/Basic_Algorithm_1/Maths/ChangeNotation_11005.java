package Maths;

import java.util.Scanner;

//입력 : 첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수이다.
//출력 : 첫째 줄에 10진법 수 N을 B진법으로 출력한다.
//A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35
//60466175 36
//ZZZZZ

public class ChangeNotation_11005 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		long N= scanner.nextInt();
		long B = scanner.nextInt();
		long S = N/B;
		String s = "";
		
		while(true) {
			if(N < 1) break;
			if( (int)N%B <=9 ) {
				s = (int)(N%B) +s ;
			} else {
				s = (char)((int)(N%B)+55) + s;
			}
			N = N/B;
		}
		System.out.println(s);
	}
}
