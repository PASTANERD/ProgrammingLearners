package sort;
import java.util.*;
import java.io.*;

public class Sorting_number_2 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		PriorityQueue<Integer> q = new PriorityQueue<Integer>();
		
		for(int i=0; i<N; i++) {
			int n = Integer.parseInt(br.readLine());
			q.add(n);
		}
		
		for(int i=0; i<N; i++) {
			sb.append(q.poll() + "\n");
		}
		
		System.out.println(sb.toString());
	}

}
