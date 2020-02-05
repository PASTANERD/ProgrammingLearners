package String_Algorithm;
import java.util.*;

public class Sub_string {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String a = new String("abc");
		Scanner sc = new Scanner(System.in);
		String P = sc.nextLine();
		String S = sc.nextLine();
		int cnt = 0;
		int max = 0;
		for(int i=0; i<P.length()-S.length()+1; i++) {
			for(int j=0; j<S.length(); j++) {
				if(P.charAt(i+j) == S.charAt(j)) {
					cnt++;
				}
			}
			if(cnt==S.length()) {
				max = cnt;
				break;
			}
		}
		if(max != 0) System.out.println(1);
		else System.out.println(0);
	}
}
