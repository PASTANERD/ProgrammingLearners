package bfs;
import java.util.*;

public class Wall_cracking_2_14442 {
	
	static int[] xg = {0,0,1,-1};
	static int[] yg = {1,-1,0,0};
	
	static class Pair {
		int x , y, z;
		Pair(int x, int y, int z){
			this.x = x;
			this.y = y;
			this.z = z;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();
		sc.nextLine();
		
		int[][] a = new int[n][m];
		int[][][] d = new int[n][m][k+1];
		for(int i=0; i<n; i++) {
			String s = sc.nextLine();
			for(int j=0; j<m; j++) {
				a[i][j] = s.charAt(j) - '0';
			}
		}
		
		Queue<Pair> q = new LinkedList<Pair>();
		d[0][0][0] = 1;
		q.add(new Pair(0,0,0));
		while(!q.isEmpty()) {
			Pair p = q.remove();
			int x = p.x;
			int y = p.y;
			int z = p.z;
			if(x==(n-1) && y==(m-1)) {
				System.out.println(d[x][y][z]);
				return;
			}
			for(int t=0; t<4; t++) {
				int nx = x+xg[t];
				int ny = y+yg[t];
				if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
				if(a[nx][ny] == 0 && d[nx][ny][z] == 0) {
					d[nx][ny][z] = d[x][y][z] + 1;
					q.add(new Pair(nx, ny, z));
				}
				if(a[nx][ny] == 1 && z<k && d[nx][ny][z+1]== 0  ) {
					d[nx][ny][z+1] = d[x][y][z] + 1;
					q.add(new Pair(nx, ny, z+1));
				}
			}
		}
		System.out.println(-1);
	}
}
