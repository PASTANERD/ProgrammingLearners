package NnM;
import java.io.*;
import java.util.*;

public class NnM_5_15654 {
	
	public static int[] num ;
	public static boolean[] used ;
	public static StringBuilder sb = new StringBuilder();;
	public static int N, M;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		num = new int[N];
		used = new boolean[N];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) 
			num[i] = Integer.parseInt(st.nextToken());
	
		Arrays.sort(num);
		go(0, "");
		System.out.println(sb);
	}
	
	public static void go(int index, String s) throws IOException {
		if(index == M) {
			sb.append(s + "\n");
			return;
		}
		for(int i=0; i<N; i++) {
			if(used[i]) continue;
			used[i] = true;
			go(index+1, s + num[i] + " ");
			used[i] = false;
		}
	}
}
