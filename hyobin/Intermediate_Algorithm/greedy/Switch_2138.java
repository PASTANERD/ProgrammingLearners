/*
전구와 스위치 Silver IV
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	992	385	313	41.789%
문제
N개의 스위치와 N개의 전구가 있다. 각각의 전구는 켜져 있는(1) 상태와 꺼져 있는 (0) 상태 중 하나의 상태를 가진다. i(1<i<N)번 스위치를 누르면 i-1, i, i+1의 세 개의 전구의 상태가 바뀐다. 즉, 꺼져 있는 전구는 켜지고, 켜져 있는 전구는 꺼지게 된다. 1번 스위치를 눌렀을 경우에는 1, 2번 전구의 상태가 바뀌고, N번 스위치를 눌렀을 경우에는 N-1, N번 전구의 상태가 바뀐다.

N개의 전구들의 현재 상태와 우리가 만들고자 하는 상태가 주어졌을 때, 그 상태를 만들기 위해 스위치를 최소 몇 번 누르면 되는지 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N(2≤N≤100,000)이 주어진다. 다음 줄에는 전구들의 현재 상태를 나타내는 숫자 N개가 공백 없이 주어진다. 그 다음 줄에는 우리가 만들고자 하는 전구들의 상태를 나타내는 숫자 N개가 공백 없이 주어진다.

출력
첫째 줄에 답을 출력한다. 불가능한 경우에는 -1을 출력한다.

예제 입력 1 
3
000
010
예제 출력 1 
3
 */
package greedy;
import java.util.*;

public class Switch_2138 {
	
	static String T;
	static char[] S;
	static int N, total=0;
	static boolean flag = false;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		sc.nextLine();
		String s = sc.nextLine();
		T = sc.nextLine();
		S = new char[N];
		
		s.getChars(0, N, S, 0);
		int ans1 = get(0,0);
		s.getChars(0, N, S, 0);
		int ans2 = get(1,0);
		
		if(flag) System.out.println(Math.min(ans1, ans2));
		else System.out.println(-1);
	}
	
	public static int get(int start, int ans) {
		if(start == 1) {
			press(0, 0);
			ans++;
		}
		
		for(int i=0; i<(N-1); i++) {
			if(check(i)) {
				int type = 1;
				if(i==(N-2)) type = 2;
				press(i+1, type) ;
				total --;
				ans++;
			}
		}

		if(T.equals(String.copyValueOf(S))) {
			flag = true;
			return ans;
		}
		return Integer.MAX_VALUE;
	}
	
	public static char change(int i) {
		if(S[i]=='0') {
			return ('1');
		}
		else return ('0');
	}
	
	public static boolean check(int i) {
		if(S[i] == T.charAt(i))
			return false;
		else return true;
	}
	
	public static void press(int n, int type) {
		if(type != 0) S[n-1] = change(n-1);
		S[n] = change(n);
		if(type != 2) S[n+1] = change(n+1);
	}

}
