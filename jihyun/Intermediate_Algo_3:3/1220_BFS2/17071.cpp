//17071
//BFS 조금 주의해야 함! (dist 활용 차이)
//시간복잡도 : 1000000 (500000*2)

#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;
int dist[500001][2];    //[i][j] : i는 수빈이의 위치, j=0은 홀수 time / j=1은 짝수 time
                        //수빈이의 같은 위치를 홀/짝 시간에 따라 다시 방문할 수 있음

int main(){
    ios_base::sync_with_stdio(false);

    int N, K;   //수빈 위치, 동생 위치
    cin >> N >> K;
    
    memset(dist, -1, sizeof(dist));
    
    queue<pair<int,int>> q;
    q.push({N,0});
    dist[N][0] = 0;
    
    while(!q.empty()){
        int cur, t;
        tie(cur,t) = q.front(); q.pop();
        
        for(int i : {cur+1, cur-1, cur*2}){
            if(0<=i && i<=500000){
                if(dist[i][1-t] == -1){
                    dist[i][1-t] = dist[cur][t] + 1;
                    q.push({i,1-t});
                }
            }
        }
    }
    
    int answer = -1;
    for(int t=0; ;t++){
        K += t;
        if(K > 500000) break;
        if(dist[K][t%2] <= t){
            answer = t; break;}
    }
    
    cout << answer;
}

