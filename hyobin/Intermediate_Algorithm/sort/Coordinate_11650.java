package sort;
import java.io.*;
import java.util.*;

public class Coordinate_11650 {
	
	static class Coor implements Comparable<Coor>{
		int x, y;
		Coor(int x, int y){
			this.x = x;
			this.y = y;
		}
		
		public int compareTo(Coor o){
			if(this.y != o.y) return this.y-o.y;
			else return this.x - o.x;
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		int N = Integer.parseInt(br.readLine());
		PriorityQueue<Coor> q = new PriorityQueue<>();
		StringBuilder sb = new StringBuilder();
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			q.add(new Coor(x, y));
		}
		
		for(int i=0; i<N; i++) {
			Coor c = q.poll();
			sb.append(c.x + " " + c.y + "\n");
		}
		
		System.out.println(sb.toString());
	}

}
