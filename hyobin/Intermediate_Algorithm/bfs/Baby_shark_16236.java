package bfs;
import java.util.*;
import java.io.*;

public class Baby_shark_16236 {
	
	static int N, eat_size;
	static int shark_size = 2;
	static int[][] map;
    static int[] xg = {-1, 0, 0,1};
    static int[] yg = {0,-1, 1, 0};
    static P EAT;
    static TreeMap<Integer, LinkedList<P>> fish_list = new TreeMap<>(); 
    
	static class P {
		int x,  y, c;
		P(int x, int y){
			this.x = x;
			this.y = y;
		}
		P(int x, int y, int c){
			this.x = x;
			this.y = y;
			this.c = c;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		boolean[][] check = new boolean[N+1][N+1];
		map = new int[N+1][N+1];
		P Shark = null;
		
		StringTokenizer st = null;
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				int temp =  Integer.parseInt(st.nextToken());
				if(temp == 9) {
					Shark = new P(i,j);
					temp = 0;
				}
				else if(temp !=0 ) {
					if(!fish_list.containsKey(temp)) 
						fish_list.put(temp, new LinkedList<P>());
					fish_list.get(temp).add(new P(i,j,temp));
				}
				map[i][j] = temp;
			}
		}
		
		Queue<P> q = new LinkedList<>();
		Queue<P> fishs = new LinkedList<>();
		q.add(Shark);
		check[Shark.x][Shark.y] = true;
		int time = 0;
		int total_eat = 0;
		A : while(!q.isEmpty()) {
			int size = q.size();
			for(int s=0; s<size; s++) {
				P p = q.poll();
				
//				System.out.println("현재 위치 : " + p.x + " " + p.y);
				fishs.clear();
				for(int num : fish_list.keySet()) {
					if(num < shark_size) { //먹을 수 있는 물고기 골라내기
						for(P fish : fish_list.get(num)){
							fishs.add(fish);
						}
					} else break;
				}
				
//				for(P now : fishs) {
//					System.out.println( "물고기 : " + now.x + " " + now.y +" (" + now.c+ ")");
//				}
				
				if(fishs.size() != 0) {
					int d =  get_distance(p, fishs);
					if(d==0) break A;
					time += d;
					q.add(EAT);
					total_eat += 1;
					if(total_eat >= shark_size) {
						shark_size++;
						total_eat=0;
					}
					fish_list.get(EAT.c).remove(EAT);
				}
				
//				System.out.println("total_eat : " + total_eat);
//				System.out.println("shark_size : " + shark_size );
//				System.out.println("time : " + time+ "\n");
			}
		}
		System.out.println(time);
	}
	
	static int get_distance(P shark, Queue<P> fish) {
		Queue<P> queue = new LinkedList<>();
		boolean[][] check = new boolean[N][N];
		queue.add(shark);
		int distance = 1;
		boolean flag = false;
		int tx = 21, ty = 21;
		
		while(!queue.isEmpty()) {
			int size = queue.size();
			for(int s=0; s<size; s++) {
				P p = queue.poll();
				for(int i=0; i<4; i++) {
					int nx = p.x + xg[i];
					int ny = p.y + yg[i];
					if(outOfBound(nx, ny))
						continue;
					
//					System.out.println(nx + " , " +ny);
					if(map[nx][ny] > shark_size)  //지나갈 수 없으면
						continue;
					
					if(check[nx][ny])
						continue;
					
					for(P f : fish) {
						if(nx == f.x && ny==f.y) {
							if((nx < tx) || (nx==tx) && (ny<ty)) {
								EAT = f;
								tx = nx;
								ty = ny;
//								System.out.println(tx + " , " + ty);
								flag = true;
							}
						}
					}
					
					check[nx][ny] = true;
					queue.add(new P(nx, ny));
				}
			}
			if(flag) {
//				System.out.println("도착!! : " + EAT.x + " " +  EAT.y + " (" + distance + ")");
//				System.out.println();
				map[tx][ty] = 0;
				return distance;
			}
			distance++;
		}
		return 0;
	}
	
	   static boolean outOfBound(int x, int y) {
		      if (x < 0 || y < 0 || x >= N || y >= N)
		         return true;
		      return false;
	   }

	   static void print(int[][] map2) {
		   for(int[] m : map2) {
			   for(int i : m) {
				   System.out.print(i);
			   }
			   System.out.println();
		   }
		   System.out.println();
	   }
	   
	   static void printmap(Map<Integer, LinkedList<P>> map) {
		   for(Integer num : map.keySet()) {
			   for(P p : map.get(num)) {
				   System.out.println(num + " : " + p.x + " " + p.y);
			   }
		   }
	   }
}
