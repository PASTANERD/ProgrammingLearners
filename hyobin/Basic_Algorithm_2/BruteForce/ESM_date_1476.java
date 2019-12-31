package BruteForce;

import java.util.Scanner;

public class ESM_date_1476 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int E = scanner.nextInt();
		int S = scanner.nextInt();
		int M = scanner.nextInt();

		if(E==15) E=0;
		if(S==28) S=0;
		if(M==19) M=0;
		
		for(long i=1; i<1000000000; i++) {
			if(i%15==E && i%28==S && i%19==M) {
				System.out.println(i);
				break;
			}
		}
	}

}
