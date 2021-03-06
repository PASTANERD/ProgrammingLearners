/*
수빈이는 동생과 숨바꼭질을 하고 있다. 
수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
수빈이는 걷거나 순간이동을 할 수 있다. 
만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 
수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

5 17

4
 */
package bfs;
import java.util.*;

public class Hide_n_Seek_1697 {
	static int min = 100001;
	static boolean[] check = new boolean[100000+1];
	
	public static void bfs(int start, int k) {
		Queue<Pair> q = new LinkedList<Pair>();
		q.add(new Pair(start, 0));
		while(!q.isEmpty()) {
			Pair x = q.remove();
			int n = x.n;
			int c = x.c;
			if(n == k) {
				if (min > c) min = c;
				break;
			}
			if(n<0 || n>100000) continue;
			if(check[n]==true) continue;
			check[n] = true;
			
			q.add(new Pair(n-1, c+1));
			if(n<k) {
				q.add(new Pair(n+1, c+1));
				q.add(new Pair(n*2, c+1));
			}
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int k = scanner.nextInt();
		
		if(n==k) {
			System.out.println(0);
			return;
		}
		bfs(n,k);
		System.out.println(min);
	}
	
	public static class Pair {
		int n;
		int c;
		Pair(int n, int c){
			this.n = n;
			this.c = c;
		}
	}

}
