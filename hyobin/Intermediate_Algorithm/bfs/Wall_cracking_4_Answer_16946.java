package bfs;
import java.util.*;
import java.io.*;

public class Wall_cracking_4_Answer_16946 {
	static int N, M;
	static char[][] map;
	static int[][] visit;
	static int groupNumber;
	
    static int[] dy = {1,-1, 0, 0};
    static int[] dx = {0, 0, 1,-1};
    static int[] group;
    static LinkedList<Integer> groupAdded;
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
	      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	      String[] in = br.readLine().split(" ");
	      N = Integer.parseInt(in[0]);
	      M = Integer.parseInt(in[1]);
	      map = new char[N][M];
	      for(int i=0; i<N; i++) {
	    	  map[i] = br.readLine().toCharArray();
	      }
	      visit = new int[N][M];
	      group = new int[1000*1000];
	      groupAdded = new LinkedList<>();
	      
	      groupNumber = 0;
	      Queue<int[]> q = new LinkedList<>();
	      for(int i=0; i<N; i++)
	    	  Arrays.fill(visit[i], -1);
	      for(int i=0; i<N; i++) {
	    	  for(int j=0; j<M; j++) {
	    		  if(map[i][j]=='1') 
	    			  continue;
	    		  if(visit[i][j] != -1) 
	    			  continue;
	    		  visit[i][j] = groupNumber;
	    		  q.add(new int[] {i,j}); //0이고, 아직 visit하지 않은 곳
	    		  int size = bfs(q); //bfs를 돈다.
	    		  
	    		  group[groupNumber++] = size; //group 에 size 저장
	    	  }
	      }
	      
	     StringBuilder sb = new StringBuilder();
	     for(int i=0; i<N; i++) {
	    	 for(int j=0; j<M; j++) {
	    		 if(map[i][j] == '0') {
	    			 sb.append(map[i][j]);
	    		 } else {
	    			 int space = getSpace(i,j);
	    			 sb.append(space);
	    		 }
	    	 }
	    	 sb.append("\n");
	     }
	     
	     System.out.println(sb.toString());
	     br.close();
	      
	      
	      
	}
	
	static int getSpace(int y, int x) {
		groupAdded.clear();
		int space = 1;
		for(int k=0; k<4; k++) {
	         int nY = y + dy[k];
	         int nX = x + dx[k];
	         if (outOfBound(nY, nX))
	            continue;
	         if (visit[nY][nX] == -1)
	            continue;
	         int idx = visit[nY][nX];
	         if(groupAdded.contains(idx)) 
	        	 continue;
	         groupAdded.add(idx);
	         space += group[idx];
		}
		return space % 10;
	}

   static int bfs(Queue<int[]> q) {
	  int size = 0;
	  while (!q.isEmpty()) {
	     size++;
	     
	     int[] p = q.poll();
	     int y = p[0];
	     int x = p[1];
	     for (int i = 0; i < 4; i++) {
	        int nY = y + dy[i];
	        int nX = x + dx[i];
	        if (outOfBound(nY, nX))
	           continue;
	        if (visit[nY][nX] != -1)
	           continue;
	        if (map[nY][nX] == '1')
	           continue;
	        
	        visit[nY][nX] = groupNumber; //visit[][] 에다가 체크.
	        q.offer(new int[] {nY, nX});
	     }
	  }
	  return size;
   }
   
   static boolean outOfBound(int y, int x) {
	      if (y < 0 || x < 0 || y >= N || x >= M)
	         return true;
	      return false;
	   }

}
