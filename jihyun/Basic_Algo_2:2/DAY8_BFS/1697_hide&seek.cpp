//1697
#include<iostream>
#include<queue>

using namespace std;

bool check[100001] = {false,};
queue<int> q;
int dist[100001] = {0,};
int MAX;

void bfs(int x){
    check[x] = true;
    dist[x] = 0;
    q.push(x);
    
    while(!q.empty()){
        int y = q.front(); q.pop();
        if(y-1 >= 0){
            if(!check[y-1]){
                q.push(y-1);
                check[y-1] = true;
                dist[y-1] = dist[y] + 1;
            }
        }
        if(y+1 < MAX){
            if(!check[y+1]){
                q.push(y+1);
                check[y+1] = true;
                dist[y+1] = dist[y] + 1;
            }
        }
        if(y*2 < MAX){
            if(!check[y*2]){
                q.push(y*2);
                check[y*2] = true;
                dist[y*2] = dist[y] + 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    MAX = max(n,k) + 2;
    
    bfs(n);
    cout << dist[k];
}
