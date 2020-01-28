/*
문제
정수 N과 K가 주어졌을 때, 다음 두 조건을 만족하는 문자열 S를 찾는 프로그램을 작성하시오.

문자열 S의 길이는 N이고, 'A', 'B'로 이루어져 있다.
문자열 S에는 0 ≤ i < j < N 이면서 s[i] == 'A' && s[j] == 'B'를 만족하는 (i, j) 쌍이 K개가 있다.
입력
첫째 줄에 N과 K가 주어진다. (2 ≤ N ≤ 50, 0 ≤ K ≤ N(N-1)/2)

출력
첫째 줄에 문제의 조건을 만족하는 문자열 S를 출력한다. 가능한 S가 여러 가지라면, 아무거나 출력한다. 만약, 그러한 S가 존재하지 않는 경우에는 -1을 출력한다.

예제 입력 1 
3 2
예제 출력 1 
ABB
예제 입력 2 
2 0
예제 출력 2 
BA
예제 입력 3 
5 8
예제 출력 3 
-1
예제 입력 4 
10 12
예제 출력 4 
BAABBABAAB
 */
package greedy_practice;
import java.util.*;

public class AB_12970 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		
		for(int a=0; a<=N; a++) {
			int b = N-a;
			if(a*b < K) continue;
			int[] cnt = new int[b+1]; //b의 개수
			for(int i=0; i<a; i++) {  //a의 개수
				int x = Math.min(b, K);
				cnt[x] += 1;
				K -= x;
			}
			for(int i=b; i>=0; i--) {
				for(int j=0; j<cnt[i]; j++) { //필요한 만큼 A먼저 출력
					System.out.print('A');
				}
				if( i > 0 ) {
					System.out.print('B');
				}
			}
			System.out.println();
			return; 
		}
		System.out.println(-1);
	}

}
