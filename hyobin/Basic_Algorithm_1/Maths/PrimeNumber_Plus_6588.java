package Maths;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/*
 * 8
 * 20
 * 42
 * 0
 */

public class PrimeNumber_Plus_6588 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		ArrayList mylist = new ArrayList<>();
		
		while(true) {
			String s = bf.readLine();
			if(s.equals("0")) break;
			mylist.add(Integer.parseInt(s));
		}
		
		int M = (int) Collections.max(mylist);
		boolean[] count = new boolean[M+1];
		
		for(int i=2; i<M+1; i++) {
			if( count[i] == false ){
				for (int j=i*2; j<M+1; j+=i) {
					count[j]=true;
				}
			}
		}
		
		for (int i=0; i<mylist.size(); i++) {
			int nmax=0;
			int b=0;
			int n = (int) mylist.get(i);
			for(int a=2; a<M+1; a++) {
				if(count[a]==false && a<n-1) {
					if(count[n-a]==false) {
						nmax = (nmax>(n-a)-a) ? nmax : (n-a)-a;
						b = (nmax>(n-a)-a) ? b : (n-a);
					}
				}
			}
			System.out.println(n+" = " + (n-b) + " + " + b);
		}
		
	}

}
