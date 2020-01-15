package bfs;
import java.util.*;
import java.io.*;

public class Hide_n_Seek_3_13549 {
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
		StringTokenizer tokenizer = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(tokenizer.nextToken());
        int k = Integer.parseInt(tokenizer.nextToken());
        int min = 0;
        
        if(n >= k) {
        	min = n-k;
        } else {
        	Queue<Item> queue = new LinkedList<>();
        	queue.add(new Item(0, n)); //n부터 시작
        	//index가 0부터이기 때문에, 0이랑 구분해야함
        	//그래서 Integer[] 는 기본값 null이어서, 0이랑 구분됨
        	boolean[] check = new boolean[200001];
        	
        	Item result = null;
        	while(!queue.isEmpty()) {
        		result = queue.poll();
        		int loc = result.loc;     //n
        		if(loc == k) 
        		{
        			min = result.index;
        			break;
        		}
        		if(loc*2 < 200000 && check[loc*2] == false) {
        			queue.add(new Item(result.index, loc*2));
        			check[loc*2] = true;
        		}
        		if((loc-1) > 0 && check[loc-1] == false) {
        			queue.add(new Item(result.index+1, loc-1));
        			check[loc-1] = true;
        		}
        		if(loc+1 < 200000 && check[loc+1]== false) {
        			queue.add(new Item(result.index+1, loc+1));
        			check[loc+1] = true;
        		}
        	}
        }
        System.out.println(min);
	}
}
