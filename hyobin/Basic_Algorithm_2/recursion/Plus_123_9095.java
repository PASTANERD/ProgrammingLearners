package recursion;

import java.util.Scanner;

public class Plus_123_9095 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		
		for(int i=0; i<T; i++) 
			System.out.println(go(0, scanner.nextInt()));
		
	}
	
	public static int go (int n, int goal) {
		if(n==goal) return 1;
		
		int answer = 0;
		for(int i=1; i<=3; i++)
			if(n+i <= goal) answer+=go(n+i, goal);

		return answer;
	}

}
