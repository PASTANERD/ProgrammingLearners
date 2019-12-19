package DP;

import java.util.Scanner;

public class Tiling_2xn_2_11727 {

	static int[] d;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		d = new int[N+1];
		System.out.println(topDown(N));
	}
	
	// d[n] = d[n-1] + d[n-2]; 
    public static int topDown (int n) {
        if (n == 0 || n == 1) return 1;
        if (d[n] > 0) return d[n];
  
        d[n] = 2*topDown(n-2) + topDown(n-1);
        d[n] %= 10007; 
        // 여기서 10007 나머지계산을 하지 않으면, 
        //이전의 d[n] 도 값이 전부 틀려져버리기 때문에 
        //d[n]을 구할 때 마다 10007의 나머지계산을 진행 후에 저장
  
        return d[n];
    }
}
