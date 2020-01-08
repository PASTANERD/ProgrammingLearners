//13913
#include<iostream>
#include<queue>

using namespace std;

bool visit[2001][2001] = {{false,},};
int dist[2001][2001] = {{0,}};
queue<pair<int,int>> q;
int MAX;

void bfs(int x){
    visit[x][0] = true;
    dist[x][0] = 0;
    q.push(make_pair(x,0));
    
    while(!q.empty()){
        int y = q.front().first;
        int cur_clip = q.front().second;
        q.pop();
        
        //copy
        int new_clip = y;
        if(!visit[y][new_clip] && new_clip < MAX){
            visit[y][new_clip] = 1;
            q.push(make_pair(y,new_clip));
            dist[y][new_clip] = dist[y][cur_clip] + 1;
        }
        
        //paste
        if(cur_clip != 0 && y+cur_clip < MAX){
            int new_y = y + cur_clip;
            if(!visit[new_y][cur_clip]){
                visit[new_y][cur_clip] = true;
                q.push(make_pair(new_y,cur_clip));
                dist[new_y][cur_clip] = dist[y][cur_clip] + 1;
            }
        }
        
        //erase
        if(y-1 > 1){
            if(!visit[y-1][cur_clip]){
                visit[y-1][cur_clip] = true;
                q.push(make_pair(y-1,cur_clip));
                dist[y-1][cur_clip] = dist[y][cur_clip] + 1;
            }
        }
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int s;
    cin >> s;
    if(s==1){
        cout << "0"; return 0;}
    MAX = 2*s + 1;
    bfs(1);
    int min = dist[s][1];
    for(int i=2; i<=s; i++){
        if(min > dist[s][i])
            min = dist[s][i];
    }
    cout << min;
}
