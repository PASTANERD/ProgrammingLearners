package bfs;
import java.util.*;
import java.io.*;

public class Hide_n_Seek_4_A {
	static class Item{
		int index;
		int loc;
		
		Item(int index, int loc){
			this.index = index;
			this.loc = loc;
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer tokenizer = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(tokenizer.nextToken());
        int k = Integer.parseInt(tokenizer.nextToken());
        
        if(n >= k) {
        	sb.append(String.valueOf(n-k));
        	sb.append("\n");
        	for(int i=n ; i>=k; --i) {
        		sb.append(String.valueOf(i));
        		sb.append(" ");
        	}
        } else {
        	Queue<Item> queue = new LinkedList<>();
        	queue.add(new Item(0, n)); //n부터 시작
        	//index가 0부터이기 때문에, 0이랑 구분해야함
        	//그래서 Integer[] 는 기본값 null이어서, 0이랑 구분됨
        	Integer[] parent = new Integer[200001];
        	
        	Item result = null;
        	while(!queue.isEmpty()) {
        		
        		result = queue.poll();
        		int loc = result.loc;     //n
        		if(loc == k) {
        			break;
        		}
        		if((loc-1) > 0 && parent[loc-1] == null) {
        			queue.add(new Item(result.index+1, loc-1));
        			parent[loc-1] = loc;
        		}
        		if(loc+1 < 200000 && parent[loc+1]== null) {
        			queue.add(new Item(result.index+1, loc+1));
        			parent[loc+1] = loc;
        		}
        		if(loc*2 < 200000 && parent[loc*2] == null) {
        			queue.add(new Item(result.index+1, loc*2));
        			parent[loc*2] = loc;
        		}
        	}
        	System.out.println(result.index);
        	recursive(sb, parent, result.loc, n);
        }
        System.out.print(sb);
        br.close();
	}
	
	private static void recursive(StringBuilder sb, Integer[] par, int loc, int first) throws IOException { 
		sb.insert(0, String.valueOf(loc) + " ");
		if(loc==first) {
			return;
		}
		recursive(sb, par, par[loc], first);
	}
}
