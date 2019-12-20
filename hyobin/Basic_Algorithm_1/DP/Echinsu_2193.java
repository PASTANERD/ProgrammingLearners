package DP;

import java.util.Scanner;

public class Echinsu_2193 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] arr = new int[N];
        
        //피보나치로 풀며 됨. 
        if (N == 1) {
            arr[0] = 1;
        } else if (N == 2) {
            arr[1] = 1;
        } else {
            arr[0] = 1;
            arr[1] = 1;
            for (int i = 2; i < N; i++) {
                arr[i] = arr[i - 1] + arr[i - 2];
            }
        }
        System.out.println(arr[N-1]);
    }
}
