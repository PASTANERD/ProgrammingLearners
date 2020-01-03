package recursion;

import java.util.ArrayList;
import java.util.Scanner;

public class Start_Link_14889 {
	
	public static int[][] team;
	public static int answer = 100;
	public static int N;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		team = new int[N+1][N+1];
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++)
				team[i][j] = scanner.nextInt();
		}
		
		ArrayList<Integer> team1 = new ArrayList<>();
		ArrayList<Integer> team2 = new ArrayList<>();
		team1.add(1);
		go(2, team1, team2, 0, 0);
		System.out.println(answer);
	}
	
	public static void go(int i, ArrayList<Integer> team1, ArrayList<Integer> team2, int sum1, int sum2) {
		ArrayList<Integer> team_1 = new ArrayList<>();
		ArrayList<Integer> team_2 = new ArrayList<>();
		team_1.addAll(team1);
		team_2.addAll(team2);
		
		if(team1.size() == N/2 && team2.size()==N/2) {   //꽉차면
			int score = Math.abs(sum1-sum2);
			if(answer > score) answer = score;
			return;
		}
		
		if(team1.size() < N/2) {        //1번팀에 합류
			team_1.add(i);
			go(i+1, team_1, team2, sum1+getScore(i, team1), sum2);
		}
		
		if(team2.size() < N/2) {       //2번팀에 합류
			team_2.add(i);
			go(i+1, team1, team_2, sum1, sum2+getScore(i, team2));
		}
	}

	public static int getScore(int n, ArrayList<Integer> team1) {
		int sum = 0;
		if(team1.size() < 1) return 0;
		for(int i=0; i<team1.size(); i++) 
			sum += (team[team1.get(i)][n] + team[n][team1.get(i)]);
		return sum;
	}
	
	public static String printArrayList(ArrayList<Integer> A) {
		String S = "";
		for(int i =0; i<A.size(); i++) {
			S += A.get(i) + " ";
		}
		return S;
	}
}
