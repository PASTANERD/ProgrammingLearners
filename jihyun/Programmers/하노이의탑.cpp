#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int start, int to, int via){
    if(n==1){
        answer.push_back({start,to}); return;
    }
    
    hanoi(n-1,start,via,to);
    answer.push_back({start,to});
    hanoi(n-1,via,to,start);
}

vector<vector<int>> solution(int n) {
    
    hanoi(n,1,3,2);
    
    return answer;
}


/*
 재귀
 move(N,from,to) : N번 원반을 from에서 to로 옮긴다.
 
 hanoi(N,start,to,via)
    basis : if(N==1) move (1,start, to)
    
    hanoi(N-1,start,via,to)
    move (N,start,to)
    hanoi(N-1,via,to,start)
 */
	
