/*
문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 길이가 최대 50인 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다.

출력
첫째 줄에 정답을 출력한다.

예제 입력 1 
55-50+40
예제 출력 1 
-35
 */
package greedy_practice;
import java.util.*;
import java.io.*;

public class Losted_1541 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		s += "*";
		
		String num = "";
		int n = 0;
		boolean flag = false;
		int ans = 0;
		char pre_c = '+';
		for(char c : s.toCharArray()) {
			if(Character.isDigit(c)) {
				num += c;
			} else {
				n = Integer.parseInt(num);
//				System.out.print(num + " ");
				if(pre_c=='-' || (pre_c=='+' && flag==true)) {
//					System.out.print(" - \n");
					ans -= n;
					flag = true;
				} else {
//					System.out.print(" + \n");
					ans += n;
				}
				pre_c = c;
				num = "";
			}
		}
		
		System.out.println(ans);
	}

}
