/*
욱제는 학교 숙제로 크기가 8×8인 체스판에서 탈출하는 게임을 만들었다. 체스판의 모든 칸은 빈 칸 또는 벽 중 하나이다. 욱제의 캐릭터는 가장 왼쪽 아랫 칸에 있고, 이 캐릭터는 가장 오른쪽 윗 칸으로 이동해야 한다.

이 게임의 특징은 벽이 움직인다는 점이다. 1초마다 모든 벽이 아래에 있는 행으로 한 칸씩 내려가고, 가장 아래에 있어서 아래에 행이 없다면 벽이 사라지게 된다. 욱제의 캐릭터는 1초에 인접한 한 칸 또는 대각선 방향으로 인접한 한 칸으로 이동하거나, 현재 위치에 서 있을 수 있다. 이동할 때는 빈 칸으로만 이동할 수 있다.

1초 동안 욱제의 캐릭터가 먼저 이동하고, 그 다음 벽이 이동한다. 벽이 캐릭터가 있는 칸으로 이동하면 더 이상 캐릭터는 이동할 수 없다.

욱제의 캐릭터가 가장 오른쪽 윗 칸으로 이동할 수 있는지 없는지 구해보자.

입력
8개 줄에 걸쳐서 체스판의 상태가 주어진다. '.'은 빈 칸, '#'는 벽이다. 가장 왼쪽 아랫칸은 항상 벽이 아니다.

출력
욱제의 캐릭터가 가장 오른쪽 윗 칸에 도착할 수 있으면 1, 없으면 0을 출력한다.

예제 입력 1 
........
........
........
........
........
........
........
........
예제 출력 1 
1
예제 입력 2 
........
........
........
........
........
........
##......
........
예제 출력 2 
0
예제 입력 3 
........
........
........
........
........
.#......
#.......
.#......
예제 출력 3 
0
예제 입력 4 
........
........
........
........
........
.#######
#.......
........
예제 출력 4 
1
예제 입력 5 
........
........
........
........
#.......
.#######
#.......
........
예제 출력 5 
0
 */
package bfs;
import java.util.*;
import java.io.*;

public class Maze_Escape_16954 {
	static int[] xg = {0,0,1,-1,1,1,-1,-1,0};
	static int[] yg = {1,-1,0,0,1,-1,1,-1,0};
	
	static class P {
		int x,  y;
		P(int x, int y){
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<P> list = new ArrayList<>();
		boolean[][][] check = new boolean[8][8][8];
		
		String str;
		for(int i=0; i<8; i++) {
			str = br.readLine();
			for(int j=0; j<8; j++) {
				char c = str.charAt(j);
				if(c=='#') {
					list.add(new P(i,j));
				}
			}
		}
		
		boolean flag;
		int wd = 0;
		Queue<P> q = new LinkedList<P>();
		q.add(new P(7,0));
		check[7][0][0] = true;
		while(!q.isEmpty()) {
			int size = q.size();
			A : for(int s=0; s<size; s++) {
				P p = q.poll();

				B : for(int i=0; i<9; i++) {
					int nx = p.x + xg[i];
					int ny = p.y + yg[i];
					if(outOfBound(nx, ny))
						continue;
					if(p.x==0 && p.y==7) { //도착
						System.out.println(1);
						return;
					}
					int w = Math.min(wd+1, 7);
					for(P wall : list) {
						if((wall.x+wd) == nx && wall.y ==ny) //현재 벽
							continue B;
						if((wall.x+w) == nx && wall.y==ny) //미래 벽
							continue B;
					}
					
					if(check[nx][ny][w])   //같은 시간에서 가지 않기.
						continue;
					
					check[nx][ny][w] = true;
					q.add(new P(nx, ny));
				}
			}
			wd = Math.min(wd+1, 7);
		}
		System.out.println(0);
	}
	
	   static boolean outOfBound(int x, int y) {
		      if (x < 0 || y < 0 || x >= 8 || y >= 8)
		         return true;
		      return false;
	   }

}
