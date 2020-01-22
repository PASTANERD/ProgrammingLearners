/*
문제
오늘 강호는 돌을 이용해 재미있는 게임을 하려고 한다. 먼저, 돌 세개는 그룹으로 나누어져 있으며 각각의 그룹에는 돌이 A, B, C개가 있다. 강호는 모든 그룹에 있는 돌의 개수를 같게 만들려고 한다.

강호는 돌을 단계별로 움직이며, 각 단계는 다음과 같이 이루어져 있다.

크기가 같지 않은 두 그룹을 고른다. 그 다음, 돌의 개수가 작은 쪽을 X, 큰 쪽을 Y라고 정한다. 그 다음, X에 있는 돌의 개수를 X+X개로, Y에 있는 돌의 개수를 Y-X개로 만든다.

A, B, C가 주어졌을 때, 강호가 돌을 같은 개수로 만들 수 있으면 1을, 아니면 0을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 A, B, C가 주어진다. (1 ≤ A, B, C ≤ 500)

출력
돌을 같은 개수로 만들 수 있으면 1을, 아니면 0을 출력한다.

예제 입력 1 
10 15 35
예제 출력 1 
1
예제 입력 2 
1 1 2
예제 출력 2 
0
 */
package bfs;
import java.util.*;
import java.io.*;

public class Dol_Group_12886 {
	
	static boolean[][] arr = new boolean[1501][1501];
	static boolean flag = false;
	static int A, B, C, N;
	
	static class P {
		int a;
		int b;
		P(int a, int b){
			this.a = a;
			this.b = b;
		}
	}
	
	static void bfs() {
		Queue<P> q = new LinkedList<P>();
		q.add(new P(A, B));
		while(!q.isEmpty()) {
			P now = q.remove();
			int c = N-(now.a + now.b);
			if(now.a == now.b && now.a == c)
				flag = true;
			if(arr[now.a][now.b]) continue;
			arr[now.a][now.b] = arr[now.b][now.a] = arr[c][now.a] = arr[c][now.b] = arr[now.a][c] = arr[now.b][c] = true;
			int[] a = {now.a, now.b, c};
			for(int i=0; i<3; i++) {
				for(int j=0; j<3; j++) {
					if(a[i] < a[j]) {
						q.add(new P(a[i]*2, a[j]-a[i]));
					}
				}
			}
		}
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		A = sc.nextInt();
		B = sc.nextInt();
		C = sc.nextInt();
		N = A + B + C;
		
		if(N%3 != 0) {
			System.out.println(0);
			return;
		}
		
		bfs();
		if(flag) System.out.println(1);
		else System.out.println(0);
	}
}
