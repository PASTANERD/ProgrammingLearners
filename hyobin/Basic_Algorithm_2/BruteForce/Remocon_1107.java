package BruteForce;
//실패

import java.util.Arrays;
import java.util.Scanner;

public class Remocon_1107 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();        //목표 숫자
		
		int M = scanner.nextInt();
		int not_used_idx = 0;
		int used_idx = 1;
		int[] used = new int[10-M+1];          //사용되는 숫자
		int[] not_used = new int[M];
		
		for(int i=0; i<M; i++) not_used[i] = scanner.nextInt();
		Arrays.parallelSort(not_used);
		
		for(int i=0; i<10; i++) {              //입력 받기
			if(not_used_idx < M) {
				if(not_used[not_used_idx] == i) {
					not_used_idx++;
					continue;
				}
			}
			used[used_idx++] = i;
		}
		
		int number = 1000000;
		int pre_number= 1000000;
		int[] label = new int[6+1];
		
		Loop1 : for(int a=0; a<used.length; a++) {
			for(int b=0; b<used.length; b++) {
				if(label[2] == 1 && b==0) continue;
				for(int c=0; c<used.length; c++) {
					if(label[3] == 1 && c==0) continue;
					for(int d=0; d<used.length; d++) {
						if(label[4] == 1 && d==0) continue;
						for(int e=0; e<used.length; e++) {
							if(label[5] == 1 && e==0) continue;
							for(int f=0; f<used.length; f++) {
								if(label[6] == 1 && f==0) continue;
								if(used.length == 1) break Loop1;
								number = used[a]*100000 + used[b]*10000 + used[c]*1000 + used[d]*100 + used[e]*10 + used[f];
								if(number > N) {
									break Loop1;
								}
								pre_number = number;
							}
							label[6] = 1;
						}
						label[5] = 1;
					}
					label[4] = 1;
				}
				label[3] = 1;
			}
			label[2] = 1;
		}
//		System.out.println("number : " + number);
//		System.out.println("pre_number : " + pre_number);

		int small = Math.min(Math.abs(N-pre_number), Math.abs(N-number));
		int answer = Math.min(Math.abs(N-100), (int)(N+"").length() + small);
		
//		System.out.println("둘 중에 가까운 거리 : " + small);
//		System.out.println("100번 부터 : " + Math.abs(N-100));
//		System.out.println("리모콘으로 : " + ((int)(N+"").length() + small));
		System.out.println(answer);
	}
}
