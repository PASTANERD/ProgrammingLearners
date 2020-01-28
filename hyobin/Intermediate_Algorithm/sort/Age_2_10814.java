package sort;
import java.util.*;

public class Age_2_10814 {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);	
		
		int n= sc.nextInt();
		
		String arr[][]=new String[n][2]; // 나이, 이름
		
		for(int i=0;i<arr.length;i++) {
			for(int j=0;j<2;j++) {
				arr[i][j] = sc.next();			
			}
			
		}
	
		
		Arrays.sort(arr,new Comparator<String[]>() { // 0:나이 , 1:이름

			@Override
			public int compare(String[] o1,String[] o2) {
											
					return Integer.compare(Integer.parseInt(o1[0]), Integer.parseInt(o2[0]));
			
			}		
			
		});
		
		for(int i=0;i<arr.length;i++) {
	
				System.out.println(arr[i][0]+" "+arr[i][1]);
		
		}
		
	}
	
}