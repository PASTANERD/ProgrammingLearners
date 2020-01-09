package bfs;
import java.util.*;
import java.io.*;

public class Hide_n_Seek_4_A {
	static class Item{
		int index;
		int loc;
		
		Item(int idex, int loc){
			this.index = index;
			this.loc = loc;
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer tokenizer = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(tokenizer.nextToken());
        int k = Integer.parseInt(tokenizer.nextToken());
        
        if(n >= k) {
        	bw.write(String.valueOf(n-k));
        	bw.write("\n");
        	for(int i=n ; i>=k; --i) {
        		bw.write(String.valueOf(i));
        		bw.write(" ");
        	}
        } else {
        	Queue<Item> queue = new LinkedList<>();
        	queue.add(new Item(0, n)); //n부터 시작
        	int[] parent = new int[200001];
        	
        	Item result;
        	while(!queue.isEmpty()) {
        		result = queue.poll();
        		int loc = result.loc;
        	}
        }
	}

}
