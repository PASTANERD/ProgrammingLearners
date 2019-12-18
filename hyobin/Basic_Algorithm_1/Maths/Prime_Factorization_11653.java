package Maths;

//N의 소인수분해 결과를 한 줄에 하나씩 오름차순으로 출력한다.
//입력 72
//출력 2 2 2 3 3

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
