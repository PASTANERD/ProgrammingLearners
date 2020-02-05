package divide_n_conquer;
import java.util.*;
import java.io.*;

public class Number_Card_10815 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		long[] list = new long[20000001];
		
		int N = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			int n = Integer.parseInt(st.nextToken());
			list[n+10000000]++;
		}
		
		int M = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<M; i++) {
			int n = Integer.parseInt(st.nextToken());
			System.out.print(list[n+10000000]+ " ");
		}
	}
}