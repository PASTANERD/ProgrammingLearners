package bfs;
import java.util.*;
import java.io.*;

public class Prime_1963 {
	
	static int N = 10000;
	static int[] prime = new int[N];
	static boolean[] check;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		IsPrimeNumber();
		A : for(int t=0; t<T; t++) {
			int num = sc.nextInt();
			int target = sc.nextInt();
			check = new boolean[N];
			if(num==target) {
				System.out.println(0);
				continue A;
			}
			
			Queue<Integer> q = new LinkedList<>();
			q.add(num);
			int count = 1;
			while(!q.isEmpty()) {
				int size =q.size();
				for(int s= 0; s<size; s++) {
					int now = q.poll();
					for(int i=1; i<=4; i++){
						int n = (int) (now/Math.pow(10, i));
						n *= (Math.pow(10, i));
						n += (int)(now%(Math.pow(10, i-1)));
						for(int j=0; j<10; j++) {
							int m = n + (int)(Math.pow(10, i-1))*j;
							if(prime[m]==0) continue;
							if(check[m]) continue;
							if(m < 1000) continue;
							if(m == target) {
								System.out.println(count);
								continue A;
							}
							check[m] = true;
							q.add(m);
						}
					}
				}
				count++;
			}
			System.out.println("Impossible");
		}
	}
	
	public static void IsPrimeNumber() {
		for(int i=2; i<N; i++) 
			prime[i] = i;
		
		for(int i=2; i<N; i++) {
			if(prime[i]==0) 
				continue;
			for(int j= i+i; j<N; j+=i)
				prime[j] = 0;
		}
	}

}
