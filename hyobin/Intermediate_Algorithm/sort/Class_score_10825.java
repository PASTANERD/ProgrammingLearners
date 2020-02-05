package sort;
import java.io.*;
import java.util.*;

public class Class_score_10825 {
	
	static class Class implements Comparable<Class>{
		int first, second, third;
		String name;
		
		Class(int first, int second, int third, String name){
			this.first = first;
			this.second = second;
			this.third = third;
			this.name = name;
		}
		
		public int compareTo(Class o) {
			if(this.first != o.first) return o.first - this.first;
			else if(this.second != o.second) return this.second - o.second;
			else if(this.third != o.third) return o.third - this.third;
			else return this.name.compareTo(o.name);
		}
	}
	
	static String change(String name) {
//		return name;
		char c =name.charAt(0);
		if( c >= 'a' && c<= 'z' ) return (c-'A') + name.substring(1);
		else return name;
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		int N = Integer.parseInt(br.readLine());
		PriorityQueue<Class> q = new PriorityQueue<>();
		StringBuilder sb = new StringBuilder();
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			String name = st.nextToken();
			int first = Integer.parseInt(st.nextToken());
			int second = Integer.parseInt(st.nextToken());
			int third = Integer.parseInt(st.nextToken());
			q.add(new Class(first, second, third, name));
		}
		
		for(int i=0; i<N; i++) {
			Class c = q.poll();
			sb.append(c.name + "\n");
		}
		
		System.out.print(sb.toString());
	}

}
