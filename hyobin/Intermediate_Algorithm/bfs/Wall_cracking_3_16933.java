/*
문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다. 이동하지 않고 같은 칸에 머물러있는 경우도 가능하다. 이 경우도 방문한 칸의 개수가 하나 늘어나는 것으로 생각해야 한다.

이번 문제에서는 낮과 밤이 번갈아가면서 등장한다. 가장 처음에 이동할 때는 낮이고, 한 번 이동할 때마다 낮과 밤이 바뀌게 된다. 이동하지 않고 같은 칸에 머무르는 경우에도 낮과 밤이 바뀌게 된다.

만약에 이동하는 도중에 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 K개 까지 부수고 이동하여도 된다. 단, 벽은 낮에만 부술 수 있다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000), K(1 ≤ K ≤ 10)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.

예제 입력 1 
1 4 1
0010
예제 출력 1 
5
예제 입력 2 
1 4 1
0100
예제 출력 2 
4
예제 입력 3 
6 4 1
0100
1110
1000
0000
0111
0000
예제 출력 3 
15
예제 입력 4 
6 4 2
0100
1110
1000
0000
0111
0000
예제 출력 4 
9
 */
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
