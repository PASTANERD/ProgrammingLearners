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
	
	static ArrayList<P> list = new ArrayList<>(); //check대신
	static boolean flag = false;
	
	class P {
		int a;
		int b;
		int c;
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getEnclosingInstance().hashCode();
			result = prime * result + a;
			result = prime * result + b;
			result = prime * result + c;
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			P other = (P) obj;
			if (!getEnclosingInstance().equals(other.getEnclosingInstance()))
				return false;
			if (a != other.a)
				return false;
			if (b != other.b)
				return false;
			if (c != other.c)
				return false;
			return true;
		}
		P(int a, int b, int c){
			this.a = a;
			this.b = b;
			this.c = c;
		}
		private Dol_Group_12886 getEnclosingInstance() {
			return Dol_Group_12886.this;
		}
	}
	
	public void bfs(int A, int B, int C) {
		Queue<P> q = new LinkedList<P>();
		q.add(new P(A, B, C));
		while(!q.isEmpty()) {
			P now = q.remove();
			if(now.a == now.b && now.b == now.c && now.a==now.c) {
				flag = true;
				break;
			}
			if(now.a > 500 || now.b >500 | now.c >500) continue;
			if(list.contains(now)) continue;
			list.add(now);
			if(now.a < now.b) q.add(new P(now.a*2, now.b-now.a, now.c));
			if(now.b < now.a) q.add(new P(now.a-now.b, now.b*2, now.c));
			if(now.b < now.c) q.add(new P(now.a, now.b*2, now.c-now.b));
			if(now.c < now.b) q.add(new P(now.a, now.b-now.c, now.c*2));
			if(now.c < now.a) q.add(new P(now.a-now.c, now.b, now.c*2));
			if(now.a < now.c) q.add(new P(now.a*2, now.b, now.c-now.a));
		}
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		
		Dol_Group_12886 M = new Dol_Group_12886();
		M.bfs(A, B, C);
		if(flag) System.out.println(1);
		else System.out.println(0);
	}

}
