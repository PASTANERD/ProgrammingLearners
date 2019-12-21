package DP;
import java.util.*;

//int 대신 long을 써야하는 이유
//int = -2147483648 ~ 2147483648 (4bytes)
//long = -2147483648L ~ 2147483648L ( 4bytes ) ??
//long long = -9223372036854775808i64 (8bytes)
//D안에 (k-1) + (k-1) + (k-1) 가 될 수 있으므로
//int는 이 값을 담지 못해서 이상한 값이 나옴. (-값)

public class Plus_123_3_15988 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int max = 1000000;
		int k = 1000000009;
		long[] D = new long[max+1];
		Scanner scanner = new Scanner(System.in);
		D[1] = 1;
		D[2] = 2;
		D[3] = 4;
		
		int T = scanner.nextInt();
		for(int i =0; i<T; i++) {
			int n = scanner.nextInt();
			if(D[n] > 0) {
				System.out.println(D[n]);
				continue;
			}
			for(int j=4; j<=n; j++) {
				if(D[j] > 0) continue;
				D[j] = (D[j-1] + D[j-2] + D[j-3])%k;
			}
			System.out.println(D[n]);
		}
		
	}

}
