package graph;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Maze_2178 {
	static int[][] maze;
	static int min = 1000000;
	static int N, M;
	
	static void bfs(int i, int j, int c, boolean[][] check) {
		Queue<Pair> q = new LinkedList<Pair>();
		check[i][j] = true;
		q.add(new Pair(i,j+1, c+1, check));
		q.add(new Pair(i+1,j, c+1, check));
		while(!q.isEmpty()) {
			Pair node = q.remove();
			int ii = node.left;
			int jj = node.right;
			int cc = node.count;
			if(ii==0 || jj==0) continue;
			if(node.check[ii][jj]) continue;
			if(maze[ii][jj] == 0) continue;
			if(ii==N && jj==M) {
				if(cc < min) min = cc;
			}
			check[ii][jj] = true;
			q.add(new Pair(ii-1,jj, cc+1, check));
			q.add(new Pair(ii,jj-1, cc+1, check));
			q.add(new Pair(ii,jj+1, cc+1, check));
			q.add(new Pair(ii+1,jj, cc+1, check));
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		maze = new int[N+2][M+2];
		boolean[][] check = new boolean[N+2][M+2];
		
		for(int i=1; i<=N; i++) {
			String s = br.readLine();
			for(int j=0; j<s.length(); j++) {
				maze[i][j+1] = s.charAt(j) - '0';
			}
		}
		
		bfs(1, 1, 1, check);
		System.out.println(min);
	}
	
	static class Pair{
		int left;
		int right;
		int count;
		boolean[][] check;
		
		Pair(int left, int right, int count, boolean[][] check) {
			this.left = left;
			this.right = right;
			this.count = count;
			this.check = check;
		}
	}

}
