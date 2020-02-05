package greedy;
import java.util.*;
import java.io.*;

public class Longest_Subsequence_12015 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] a = new int[N];
		TreeMap<Integer, Integer> set = new TreeMap<Integer, Integer>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i=0; i<N; i++) {
			int n = Integer.parseInt(st.nextToken());
			a[i] = n;
		}
		
		for(int n : a) {
			Integer key = set.ceilingKey(n);
			//달된 키보다 크거나 같은 키 중에서 가장 작은 키 반환
			if(key!=null) { // 있음
				set.remove(key);
			}
			set.put(n, 0);
		}
		
		System.out.println(set.size());
	}

}
