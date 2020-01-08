//13913
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

bool check[100001] = {false,};
queue<int> q;
int dist[100001] = {0,};
int last_node[100001] = {0,};
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
                last_node[y-1] = y;
            }
        }
        if(y+1 < MAX){
            if(!check[y+1]){
                q.push(y+1);
                check[y+1] = true;
                dist[y+1] = dist[y] + 1;
                last_node[y+1] = y;
            }
        }
        if(y*2 < MAX){
            if(!check[y*2]){
                q.push(y*2);
                check[y*2] = true;
                dist[y*2] = dist[y] + 1;
                last_node[y*2] = y;
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
    cout << dist[k] << endl;
    
    if(n==k){
        cout << n;
    }
    else{
        stack<int> s;
        s.push(k);
        for(int j = last_node[k]; j!=n; j = last_node[j])
            s.push(j);
        s.push(n);
        
        while(!s.empty()){
            cout << s.top() << ' '; s.pop();
        }
    }
}
