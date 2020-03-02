
//5014

#include <iostream>
#include <queue>

using namespace std;

int dist[1000001] = {0,};
bool visited[1000001] = {false,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    
    queue<int> q;
    q.push(S);
    visited[S] = true;
    dist[S] = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur+U <= F && !visited[cur+U]){
            dist[cur+U] = dist[cur] + 1;
            visited[cur+U] = true;
            q.push(cur+U);
        }
        if(cur-D >= 1 && !visited[cur-D]){
            dist[cur-D] = dist[cur] + 1;
            visited[cur-D] = true;
            q.push(cur-D);
        }
    }
    
    if(S!=G && dist[G] == 0 )
        cout << "use the stairs\n";
    else
        cout << dist[G];
}

