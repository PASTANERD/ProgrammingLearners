package NnM;

import java.io.*;
import java.util.*;

public class NnM_3_15651 {
	
	public static int N, M;
	public static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer stk = new StringTokenizer(br.readLine());
		N = Integer.parseInt(stk.nextToken());
		M = Integer.parseInt(stk.nextToken());
		
		go(0 , "");
		System.out.println(sb);
	}
	
	public static void go(int index, String s) throws IOException {
		if(index == M) {
			sb.append(s + "\n");
			return;
		}
		for(int i=1; i<=N; i++) go(index+1, s + i + " ");
	}
}
