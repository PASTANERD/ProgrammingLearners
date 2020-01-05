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
		ArrayList<Integer> prime = new ArrayList<Integer>();
		
		for(int i=2; i<M+1; i++) {
			if( count[i] == false ){
				prime.add(i);
				for (int j=i*2; j<M+1; j+=i) {
					count[j]=true;
				}
			}
		}
		
		for (int i=0; i<mylist.size(); i++) {
			int n = (int) mylist.get(i);
			for(Integer a : prime ) {
				if(count[n-a]==false) {
					System.out.println( n + " = " + a + " + " + (n-a));
					break;
				}
			}
		}
	}

}
