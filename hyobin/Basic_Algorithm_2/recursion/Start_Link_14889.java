package recursion;

import java.util.Scanner;

public class Start_Link_14889 {
	
	public static int[][] team;
	public static int answer = 0;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		team = new int[N][N];
		
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				team[i][j] = scanner.nextInt();
		
	}

}
