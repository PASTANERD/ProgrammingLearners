package bfs;
import java.util.*;

public class Wall_cracking_2_Answer_14442 {
	
	static int[] xg = {0,0,1,-1};
	static int[] yg = {1,-1,0,0};

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();
		sc.nextLine();
		
		int[][] map = new int[n][m];
		for(int i=0; i<n; i++) {
			String s = sc.nextLine();
			for(int j=0; j<m; j++) {
				map[i][j] = s.charAt(j) - '0';
			}
		}
		
		int[][] visit = new int[n][m];
		for(int i=0; i<n; i++) 
			for(int j=0; j<m; j++)
				visit[i][j] = Integer.MAX_VALUE;
		
		Queue<pos> queue = new ArrayDeque<>();
		queue.add(new pos(0,0,0));
		visit[0][0] = 0;
		int time = 1;
		while(!queue.isEmpty()) {
			int size = queue.size();
			for(int s=0; s<size; s++) {
				pos p = queue.poll();
				if(p.x == n-1 && p.y ==m-1) {
					System.out.println(time);
					return;
				}
				
				for(int i=0; i<4; i++) {
					int nx = p.x + xg[i];
					int ny = p.y + yg[i];
					if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
					if(visit[nx][ny] > p.crashed) {  //지나간적이없으면||더많이부시고왔으면??
						if(map[nx][ny] == 0) {
							visit[nx][ny] = p.crashed;
							queue.add(new pos(nx, ny, p.crashed));
						}
						else if(p.crashed<k) {
							visit[nx][ny] = p.crashed+1;
							queue.add(new pos(nx, ny, p.crashed+1));
						}
					}
				}
			}
			time++;
		}
		System.out.println(-1);
	}

}

class pos{
	int x, y, crashed;
	pos(int x, int y, int crashed) {
		this.x = x;
		this.y = y;
		this.crashed = crashed;
	}
}
