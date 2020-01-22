package bfs;
import java.util.*;

class Pair {
	int x , y, z;
	Pair(int x, int y, int z){
		this.x = x;
		this.y = y;
		this.z = z;
	}
}

public class Wall_cracking_1_Answer_2206 {
	public static int[] dx = {1,-1, 0,0};
	public static int[] dy = {0,0,1,-1};

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		sc.nextLine();
		int[][] a = new int[n][m];
		int[][][] d = new int[n][m][2];
		for(int i=0; i<n; i++) {
			String s = sc.nextLine();
			for(int j=0; j<m; j++) {
				a[i][j] = s.charAt(j) - '0';
			}
		}
		d[0][0][0] = 1;
		Queue<Pair> q = new LinkedList<Pair>();
		q.offer(new Pair(0,0,0)); //벽을 안 부숨
		while(!q.isEmpty()) {
			Pair p = q.remove();
			int x = p.x;
			int y = p.y;
			int z = p.z;   //벽을 부순 횟수. 
			for(int k=0; k<4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if(nx <0 || nx>=n || ny<0 || ny>=m) continue;
				if(a[nx][ny] == 0 && d[nx][ny][z] == 0) { //길이고, 벽을 안 부수고/부수고 왔는데, 온적이 없으면 ,,,
					d[nx][ny][z] = d[x][y][z] + 1;  // 안부수고/부수고 몇개를 지나왔는지 +1.
					q.offer(new Pair(nx, ny, z)); //
				}
				// 여기 z=0 을 위해서 계속 가지고 가는거임.
				if(a[nx][ny] == 1 && z == 0 && d[nx][ny][z+1]==0) { //벽이고, 안부수고왔고, 부수고 간적이 없으면
					d[nx][ny][z+1] = d[x][y][z] + 1; //부수고 가고, 몇개를 지나왔는지 +1
					q.offer(new Pair(nx, ny, z+1));
				}
			}
		}
		//갈 수 있는 곳 다 돌았음...
		if(d[n-1][m-1][0] != 0 && d[n-1][m-1][1] != 0) { //n,m에 온적이 있으면
			System.out.println(Math.min(d[n-1][m-1][0], d[n-1][m-1][1]));
		} else if (d[n-1][m-1][0] != 0) { //안 부수고만 왔으면
			System.out.println(d[n-1][m-1][0]);
		} else if (d[n-1][m-1][1] != 0) { //부수고만 왔으면
			System.out.println(d[n-1][m-1][1]);
		} else {
			System.out.println(-1);
		}
	}
}
