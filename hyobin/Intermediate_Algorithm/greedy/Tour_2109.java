package greedy;
import java.util.*;
import java.io.*;

public class Tour_2109 {
	
	static class Tour implements Comparable<Tour>{
		int d, p;
		Tour(int d, int p){
			this.d = d;
			this.p = p;
		}
		@Override
		public int compareTo(Tour o) {
			if(this.d != o.d)
				return o.d-this.d;
			else 
				return o.p - this.p;
		}
	}

	public static void main(String[] args) throws IOException  {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = null;
		Tour[] T = new Tour[N+1];
		
		for(int i=0; i<N; i++){
			st = new StringTokenizer(br.readLine());
			int p = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			T[i] = new Tour(d, p);
		}
		
		T[N] = new Tour(0,0);
		Arrays.sort(T);
		
		PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());
		long money = 0;
		int day = T[0].d;
		for(Tour t : T) {
			if(day!=t.d) {
				while(day!=(t.d)) {
					if(!q.isEmpty()) {
						money+=q.poll();
					}
					day--;
				}
			}
			q.add(t.p);
		}
		System.out.println(money);
	}

}
