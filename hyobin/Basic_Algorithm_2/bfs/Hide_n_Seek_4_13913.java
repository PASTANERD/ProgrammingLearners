/*
문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

둘째 줄에 어떻게 이동해야 하는지 공백으로 구분해 출력한다.

5 17

4
5 10 9 18 17

5 17

4
5 4 8 16 17
 */
package bfs;
import java.util.*;
import java.io.*;
import print.*;

public class Hide_n_Seek_4_13913 {
	static int min;
	static boolean[] check = new boolean[100000+1];
	static int[] parent = new int[100000+1];
	static StringBuilder sb = new StringBuilder();
	
	public static void bfs(int start, int k) {
		Queue<Pair> q = new LinkedList<Pair>();
		q.add(new Pair(start, 0, 0));
		while(!q.isEmpty()) {
			Pair x = q.remove();
			int n = x.n;
			int c = x.c;
			if(n == k) {
				min = c;
				parent[n] = x.p;
				break;
			}
			if(n<0 || n>100000) continue;
			if(check[n]==true) continue;
			check[n] = true;
			parent[n] = x.p;
			q.add(new Pair(n-1, c+1, n));
			if(n<k) {
				q.add(new Pair(n+1, c+1, n));
				q.add(new Pair(n*2, c+1, n));
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
			System.out.println(n);
			return;
		}
		bfs(n,k);
		System.out.println(min);
		findparent(k,n);
		System.out.println(sb);
	}
	
	public static void findparent(int x, int n) {
		sb.insert(0,x+ " ");
		if(x==n) return;
		findparent(parent[x], n);
	}
	
	public static class Pair {
		int n;
		int c;
		int p;
		Pair(int n, int c, int p){
			this.n = n;
			this.c = c;
			this.p = p;
		}
	}

}
