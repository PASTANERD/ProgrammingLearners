package BruteForce;

import java.util.Scanner;
//가로줄을 행 ( row), 세로줄을 열, column

public class Candy_Game_3085 {

	static int MAX = 50;
	static char[][] candy = new char[MAX][MAX];
	static int N;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		int candy_max = 0;
		
		for(int i=0; i<N; i++)  //입력 받기
			candy[i] = scanner.next().toCharArray();
		
		for(int i=0; i<N; i++) {
			candy_max = max(look_row(i), look_col(i));
		}
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N-1; j++) {
				switch_row(i,j); // 가로로 바꿈
				candy_max = max(candy_max, max(look_row(i), look_col(j), look_col(j+1))); 
				switch_row(i, j); //돌려놓음
			}
		}
		
		for(int i=0; i<N-1; i++) {
			for(int j=0; j<N; j++) {
				switch_col(i, j); //세로로 바꿈
				candy_max = max(candy_max, max(look_row(i), look_row(i+1), look_col(j)));
				switch_col(i, j); //돌려놓음
			}
		}
		
		System.out.println(candy_max);
	}
	
	public static void switch_row(int i, int j) {
		if(candy[i][j] == candy[i][j+1]) return; 
		char temp = candy[i][j];
		candy[i][j] = candy[i][j+1];
		candy[i][j+1] = temp;
	}
	
	public static void switch_col(int i, int j) {
		if(candy[i][j] == candy[i+1][j]) return; 
		char temp = candy[i][j];
		candy[i][j] = candy[i+1][j];
		candy[i+1][j] = temp;
	}
	
	public static int look_row(int n) {
		int temp = 1;
		int max = 1;
		
		for(int i=0; i<N-1; i++) {
			if(candy[n][i] == candy[n][i+1]) {    //맛이 연속되면
				temp++;
			} else {                      //맛 연속 안되면
				max = max(max,temp);
				temp = 1;
			}
		}
		return max(max, temp);
	}
	
	public static int look_col(int n) {
		int temp = 1;
		int max = 1;
		
		for(int i=0; i<N-1; i++) {
			if(candy[i][n] == candy[i+1][n]) {    //맛이 연속되면
				temp++;
			} else {                      //맛 연속 안되면
				max = max(max,temp);
				temp = 1;
			}
		}
		return max(max, temp);
	}
	
	public static int max(int a, int b, int c) {
		int max = a;
		if(max<b) max = b;
		if(max<c) max = c;
		return max;
	}
	
	public static int max(int a, int b) {
		if(a<b) return b;
		return a;
	}

}
