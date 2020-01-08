/*
BOJ 알고리즘 캠프에는 총 N명이 참가하고 있다. 사람들은 0번부터 N-1번으로 번호가 매겨져 있고, 일부 사람들은 친구이다.

오늘은 다음과 같은 친구 관계를 가진 사람 A, B, C, D, E가 존재하는지 구해보려고 한다.

A는 B와 친구다.
B는 C와 친구다.
C는 D와 친구다.
D는 E와 친구다.
위와 같은 친구 관계가 존재하는지 안하는지 구하는 프로그램을 작성하시오.

5 4
0 1
1 2
2 3
3 4

1
 */
package graph;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Vector;

public class ABCDE_13023 {
	
	public static boolean[][] a = new boolean[2000][2000];   // 인접 행렬
	//public static ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>(2000);   // 인접 리스트
	public static ArrayList<Integer>[] g = new ArrayList[2000];
	public static ArrayList<Pair> edges = new ArrayList<Pair>();     //간선 리스트

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for(int i=0; i<2000; i++)
			g[i] = new ArrayList<Integer>();

		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		
		for(int i=0; i<M; i++) {
			int from = scanner.nextInt();
			int to = scanner.nextInt();
			
			edges.add(new Pair(from, to));      //모든 간선 저장
			edges.add(new Pair(to, from));
			a[from][to] = a[to][from] = true;  //연결 존재
			g[from].add(to);
			g[to].add(from);
		}
		
		M *= 2;   //bidirection
		
		for (int i=0; i<M; i++) {
			for(int j=0; j<M; j++) {
				//A -> B
				int A = (int)edges.get(i).left;
				int B = (int)edges.get(i).right;
				//C -> D
				int C = (int)edges.get(j).left;
				int D = (int)edges.get(j).right;
				if(A==B || A==C || A==D || B==C || B==D || C==D) continue;
				
				//B->C
				if(!a[B][C])  //연결이 없으면
					continue;
				
				//D->E
				for(int E : g[D]) { //D와 인접한 node 전체
					if( A==E || B==E || C==E || D==E) continue;
					System.out.println(1);
					return;
				}
			}
		}
		System.out.println(0);
		return;
		
	}
	
	static class Pair{
		int left;
		int right;
		
		Pair(int left, int right) {
			this.left = left;
			this.right = right;
		}
	}
}
