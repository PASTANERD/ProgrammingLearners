package BruteForce;

import java.util.Arrays;
import java.util.Scanner;

public class Seven_2309 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scanner = new Scanner(System.in);
		int max = 9;
		int[] height = new int[max];
		int sum = 0;
		boolean exitOuterLoop = false;
		
		for(int i=0; i<max; i++) {
			height[i] = scanner.nextInt();
			sum += height[i];
		}
		
		Arrays.parallelSort(height);
		
		for(int i=0; i<max-1; i++) {
			for(int j=i+1; j<max; j++) {
				if(sum - height[i] - height[j] == 100) {
					for(int t=0; t<max; t++) {
						if(t != i && t!=j) System.out.println(height[t]);
					}
					exitOuterLoop = true;
					break;
				}
			}
			if(exitOuterLoop == true) break;
		}
			
	}

}
