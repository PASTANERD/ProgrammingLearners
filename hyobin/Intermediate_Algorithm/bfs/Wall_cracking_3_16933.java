package bfs;
import java.util.*;

public class Wall_cracking_3_16933 {
	
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
		queue.add(new pos(0,0,0,1,1));
		visit[0][0] = 0;
		while(!queue.isEmpty()) {
			pos p = queue.poll();
			if(p.x==(n-1) && p.y==(m-1)) {
				System.out.println(p.count);
				return;
			}
			for(int i=0; i<4; i++) {
				int nx = p.x + xg[i];
				int ny = p.y + yg[i];
				if(nx<0 || ny<0 || nx>=n || ny>=m ) continue;
				if(visit[nx][ny] > p.crack) {
					if(map[nx][ny]==0) {
						visit[nx][ny] = p.crack;
						queue.add(new pos(nx, ny, p.crack, p.day*-1, p.count+1));
					} else if(p.crack < k){ //벽이면&뚫을 수 있으면
						if(p.day == 1) {
							visit[nx][ny] = p.crack+1;
							queue.add(new pos(nx, ny, p.crack+1, p.day*-1, p.count+1));
						} else {
							queue.add(new pos(p.x, p.y, p.crack, p.day*-1, p.count+1));
						}
					}
					
				}
			}
		}
		System.out.println(-1);
	}
	
	static class pos{
		int x, y, crack, day, count; //1이면 낮, -1이면 밤
		pos(int x, int y, int crack, int day, int count){
			this.x = x;
			this.y = y;
			this.crack = crack;
			this.day = day;
			this.count = count;
		}
	}

}
