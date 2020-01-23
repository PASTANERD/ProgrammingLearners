package bfs;
import java.util.*;

public class Prime_Answer_1963 {
	public static int change(int num, int index, int digit) {	
		String s = Integer.toString(num);
		StringBuilder sb = new StringBuilder(s);
		sb.setCharAt(index, (char)(digit+ '0'));
		return Integer.parseInt(sb.toString());
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		boolean[] prime = new boolean[10001];
		for(int i=2; i<=10000; i++) {
			if(prime[i]==false) {
				for(int j=i+i; j<=10000; j+=i) {
					prime[i] = true;
				}
			}
		}
		
		int t = sc.nextInt();
		while(t-- > 0) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			boolean[] c = new boolean[10001];
			int[] d = new int[10001];
			d[n] = 0;
			c[n] = true;
			Queue<Integer> q = new LinkedList<Integer>();
			q.add(n);
			while(!q.isEmpty()) {
				int now = q.remove();
				for(int i=0; i<4; i++) {
					for(int j=0; j<=9; j++) {
						int next = change(now, i, j);
						if(!prime[next] && c[next]==false && next>=1000) {
							q.add(next);
							d[next] = d[now] + 1;
							c[next] = true;
						}
					}
				}
			}
		}
	}

}
