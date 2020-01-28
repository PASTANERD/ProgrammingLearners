package sort;
import java.io.*;
import java.util.*;

public class Sorting_number_3_10989 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		int arr[] = new int[10000+1];
		
		for(int i=0; i<N; i++) {
			int n = Integer.parseInt(br.readLine());
			arr[n]++;
		}
		
		for(int i=0; i<arr.length; i++) {
			if(arr[i] != 0) {
				for(int count = 0; count<arr[i]; count++) {
					sb.append(i + "\n");
				}
			}
		}
		
		System.out.print(sb.toString());
	}

}
