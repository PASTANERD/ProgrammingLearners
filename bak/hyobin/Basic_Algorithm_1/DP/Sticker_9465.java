package DP;

import java.util.Arrays;
import java.util.Scanner;

//스티커 문제. 호랑이 우리랑 똑같다.
//출력 : 각 테스트 케이스 마다, 
//2n개의 스티커 중에서 두 변을 공유하지 않는 스티커 점수의 최댓값을 출력한다.

public class Sticker_9465 {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		//nextInt()화면 '/n'을 nextLine()이 먹음
		int T = scanner.nextInt();
		
		for(int t=0; t<T; t++) {
			int N = scanner.nextInt();
			int[][] Sticker = new int[N+1][3]; //스티커 점수
			int[][] D = new int[N+1][3]; //i번째 스티커 점수의 최댓값
			int idx = 0;
			
			for(int i=0; i<2; i++)
                for(int j=0; j<N; j++)
                    Sticker[j][i] = scanner.nextInt();

			D[0][1] = Sticker[0][0];
			D[0][2] = Sticker[0][1];
			
			for(int i=1; i<N; i++) {
				D[i][0] = Math.max(Math.max(D[i-1][0], D[i-1][1]), D[i-1][2]);
				D[i][1] = Math.max(D[i-1][0], D[i-1][2]) + Sticker[i][0];
				D[i][2] = Math.max(D[i-1][0], D[i-1][1]) + Sticker[i][1];
			}
			
			System.out.println(Math.max(Math.max(D[N-1][0], D[N-1][1]), D[N-1][2]));
		}
	}

}

/*
 * 입력
2
5
50 10 100 20 40
30 50 70 10 60
7
10 30 10 50 100 20 40
20 40 30 50 60 20 80

출력
260
290
*/

