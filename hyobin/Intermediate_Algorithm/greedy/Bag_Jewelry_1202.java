package greedy;
import java.util.*;
import java.io.*;

public class Bag_Jewelry_1202 {
	
	static class Jewerly implements Comparable<Jewerly>{
		int m, v, type;
		Jewerly(int m, int v, int type){
			this.m = m;
			this.v = v;
			this.type = type; //0이면보석, 1이면 가방
		}
		@Override
		public int compareTo(Jewerly o) {
			if(this.m != o.m)  //무게가 같지 않으면
				return this.m-o.m; //무게가 낮은 순으로
			else  //무게가 같으면
				return this.type-o.type;
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		Jewerly[] J = new Jewerly[N+K];
		
		for (int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			int m = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			J[i] = new Jewerly(m,v,0);
		}
		
		for(int i=0; i<K; i++) {
			int b = Integer.parseInt(br.readLine());
			J[i+N] = new Jewerly(b,0,1);
		}
		

		long ans = 0;
		long count = 0;
		Arrays.sort(J);
		PriorityQueue<Integer> q = new PriorityQueue<Integer>();
		for(Jewerly j : J) {
			if(count==K) break;
			if(j.type == 0) { //보석이면
				q.add(-j.v);
			} else {
				if(!q.isEmpty()) {
					ans += (long)-q.poll();
					count++;
				}
			}
		}
		System.out.println(ans);
	}

}
