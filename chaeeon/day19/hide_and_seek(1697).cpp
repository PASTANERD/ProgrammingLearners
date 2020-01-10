
/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1697
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <queue>

#define MAX 100001
#define MIN 0
using namespace std;

bool visit[MAX] = {false, };
int dist[MAX] = {-1, };

void bfs(int v, int k){
    queue<int> q;
    int current = -1;
    
    q.push(v);
    visit[v] = true;
    dist[v] = 0;
    while(current != k){
        current = q.front();
        q.pop();

        // if(current == k) break;
        
        int next =  current - 1;        
        if(next >= MIN && !visit[next]){
            q.push(next);
            dist[next] = dist[current] + 1;
            visit[next] = true;
        }
        
        next = current + 1;
        if(next < MAX && !visit[next]){
            q.push(next);
            dist[next] = dist[current] + 1;
            visit[next] = true;
        }
        
        next = 2*current;
        if(next < MAX && !visit[next]){
            q.push(next);
            dist[next] = dist[current] + 1;
            visit[next] = true;
        }
    }
    cout << dist[current]; 
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    
    bfs(N, K);

    return 0;
}
