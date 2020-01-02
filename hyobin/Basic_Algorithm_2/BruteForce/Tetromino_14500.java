package BruteForce;

import java.util.Scanner;

public class Tetromino_14500 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		int[][] paper = new int[N][M];
		int answer = 0;
		int sum = 0;
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) paper[i][j] = scanner.nextInt();
		}
		
		//타입1
		for(int i=0; i<N; i++) {
			for(int j=0; j<M-3; M++) {
				sum = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i][j+3];
				if(answer < sum) answer = sum;
			}
		}
		
		//타입2
		for(int i=0; i<N-1; i++) {
			for(int j=0; j<M-1; j++) {
				sum = paper[i][j] + paper[i][j+1] + paper[i+1][j] + paper[i+1][j+1];
				if(answer < sum) answer = sum;
			}
		}
		
		//타입3
		for(int i=0; i<N-2; i++) {
			for(int j=0; j<M-1; j++) {
				sum = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+2][j+1];
				if(answer < sum) answer = sum;
			}
		}
		
		for(int i=0; i<N-2; i++) {
			for(int j=0; j<M-1; j++) {
				sum = paper[i][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1];
				if(answer < sum) answer = sum;
			}
		}
		
		for(int i=0; i<N-1; i++) {
			for(int j=0; j<M-2; j++) {
				sum = paper[i][j] + paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2];
				if(answer < sum) answer = sum;
			}
		}
		
		
		for(int i=0; i<N-2; i++) {
			for(int j=0; j<M-1; j++) {
				sum = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j+2];
				if(answer < sum) answer = sum;
			}
		}
		
		
		//타입4
		for(int i=0; i<N-1; i++) {
			for(int j=0; j<M-1; j++) {
				sum = paper[i][j] + paper[i][j+1] + paper[i+1][j] + paper[i+1][j+1];
				if(answer < sum) answer = sum;
			}
		}
		
		for(int i=0; i<N-1; i++) {
			for(int j=0; j<M-1; j++) {
				sum = paper[i][j] + paper[i][j+1] + paper[i+1][j] + paper[i+1][j+1];
				if(answer < sum) answer = sum;
			}
		}
		
		for(int i=0; i<N-1; i++) {
			for(int j=0; j<M-1; j++) {
				sum = paper[i][j] + paper[i][j+1] + paper[i+1][j] + paper[i+1][j+1];
				if(answer < sum) answer = sum;
			}
		}
		
		for(int i=0; i<N-1; i++) {
			for(int j=0; j<M-1; j++) {
				sum = paper[i][j] + paper[i][j+1] + paper[i+1][j] + paper[i+1][j+1];
				if(answer < sum) answer = sum;
			}
		}
		
		//타입5
		for(int i=0; i<N-1; i++) {
			for(int j=0; j<M-1; j++) {
				sum = paper[i][j] + paper[i][j+1] + paper[i+1][j] + paper[i+1][j+1];
				if(answer < sum) answer = sum;
			}
		}
		
		for(int i=0; i<N-1; i++) {
			for(int j=0; j<M-1; j++) {
				sum = paper[i][j] + paper[i][j+1] + paper[i+1][j] + paper[i+1][j+1];
				if(answer < sum) answer = sum;
			}
		}
		
		for(int i=0; i<N-1; i++) {
			for(int j=0; j<M-1; j++) {
				sum = paper[i][j] + paper[i][j+1] + paper[i+1][j] + paper[i+1][j+1];
				if(answer < sum) answer = sum;
			}
		}
		
		for(int i=0; i<N-1; i++) {
			for(int j=0; j<M-1; j++) {
				sum = paper[i][j] + paper[i][j+1] + paper[i+1][j] + paper[i+1][j+1];
				if(answer < sum) answer = sum;
			}
		}
	}

}
