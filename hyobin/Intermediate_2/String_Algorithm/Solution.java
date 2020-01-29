package String_Algorithm;
import java.io.*;
import java.util.*;

class Solution {  
	int answer = 0;
	int n, m, t, k;
	boolean[] check;
   
   public static void main(String[] args) { 
      Solution m=new Solution(); 
      System.out.print(m.solution(2,4,1,3));  //3
   } 
   
   public int solution(int N, int M, int T, int K) {   
	   	this.n = N;
	   	this.m = M;
	   	this.t = T;
	   	this.k = K;
	   	
	   	dfs(0,0,new LinkedList<Integer>());
        return answer; 
    } 
   
   public void dfs(int day, int total, LinkedList<Integer> q) {
	   int q_total = 0;
	   for(int n : q) {
		   q_total+= n;
	   }
	   
	   if(q_total > this.k) return;
	   if(day == (this.n)) {
	   		if(total==this.m) {
	   			answer++;
	   		}
	   		return;
	   }
	   if(q.size() >= this.t) q.poll();
	   for(int i=0; i<=this.m-total; i++) {
		   q.add(i);
		   dfs(day+1, total+i, q);
		   if(!q.isEmpty()) q.removeLast();
	   }
   }
}
