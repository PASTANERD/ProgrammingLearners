package Maths;

import java.util.Scanner;

public class Prime_Factorization_11653 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		long N= scanner.nextInt();
		long n = N;
		boolean[] count = new boolean[(int) N+1];
		
		for(int i=2; i<=(int)N; i++) {
			if(count[i] == false) { //소수이면
				while(n%i==0) {
					System.out.println(i);
					n=n/i;
				}
				for(int j=i*2; j<=(int)N; j+=i) {
					count[j] = true;
				}
			}
		}
	}

}
