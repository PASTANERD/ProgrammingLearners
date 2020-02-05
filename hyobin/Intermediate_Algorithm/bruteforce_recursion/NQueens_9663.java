/*
문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

예제 입력 1 
8
예제 출력 1 
92
 */
package bruteforce_recursion;
import java.util.*;

public class NQueens_9663 {
	
	static int N;
	static int total= 0;
	static boolean[] l_diagonal;  // /
	static boolean[] r_diagonal;  // \
	static boolean[] _col;
	
	static boolean check(int row, int col) {
		if(l_diagonal[row+col]) return false;
		if(r_diagonal[row-col+(N-1)]) return false;
		return true;
	}
	
	static void row_(int row) {
		if(row==N) {
			total++;
			return;
		}
		
		for(int col=0; col<N; col++) { //각 row마다 모든 col에 다 넣기
			if(!_col[col]) { //col에 놓은 적이 없으면
				if(check(row, col)) { // 대각선에 없다면
					l_diagonal[row+col] = true;
					r_diagonal[row-col+(N-1)] = true;
					_col[col] = true;
					row_(row+1);
					l_diagonal[row+col] = false;
					r_diagonal[row-col+(N-1)] = false;
					_col[col] = false;
				}
			}
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		l_diagonal = new boolean[N*2];
		r_diagonal = new boolean[N*2];
		_col = new boolean[N];
		
		row_(0);
		System.out.println(total);
	}

}
