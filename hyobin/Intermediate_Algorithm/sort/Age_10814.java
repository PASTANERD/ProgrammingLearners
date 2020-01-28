package sort;
import java.io.*;
import java.util.*;

public class Age_10814 {
	
	static class People implements Comparable<People>{
		int age, c;
		String name;
		People(int age, String name, int c){
			this.age = age;
			this.name = name;
			this.c = c;
		}
		
		public int compareTo(People o) {
			if(this.age != o.age ) return this.age - o.age;
			else return this.c - o.c;
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		int N = Integer.parseInt(br.readLine());
		PriorityQueue<People> q = new PriorityQueue<>();
		StringBuilder sb = new StringBuilder();
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			int age = Integer.parseInt(st.nextToken());
			String name = st.nextToken();
			q.add(new People(age, name, i));
		}
		
		for(int i=0; i<N; i++) {
			People people = q.poll();
			sb.append(people.age + " " + people.name + "\n");
		}
		
		System.out.print(sb.toString());
	}

}
