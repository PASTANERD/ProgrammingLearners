//14502
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[8][8];
int N, M;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int zero_cnt = 0, MAX = 0;
vector<pair<int,int>> virus;

void SpreadVirus(){
    int copied_map[8][8];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            copied_map[i][j] = map[i][j];
        }
    }
    
    queue<pair<int,int>> q;
    int tmp = zero_cnt-3;
    for(auto i:virus)
        q.push(i);
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if(x >= 0 && x < N && y >=0 && y < M){
                if(copied_map[x][y] == 0){
                    copied_map[x][y] = 2;
                    q.push({x,y});
                    tmp--;
                }
            }
        }
    }
    MAX = max(MAX, tmp);
}

void MakeWalls(int cnt){
    if(cnt == 3){
        SpreadVirus();
        return;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                MakeWalls(cnt+1);
                map[i][j] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j]==2) virus.push_back({i,j});
            if(map[i][j]==0) zero_cnt++;
        }
    }
    
    //벽 세개 집합 구하기
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] != 0) continue;
            map[i][j] = 1;
            MakeWalls(1);
            map[i][j] = 0;
        }
    }
    cout << MAX;
}

