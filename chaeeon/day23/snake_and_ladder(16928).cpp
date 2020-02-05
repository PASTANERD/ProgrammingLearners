/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/16928
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * 주사위를 굴린다.
 * 해당 위치에서 사다리 또는 뱀이 있는지 확인한다.
 * 방문하지 않은 곳이면, 사다리/뱀을 타고 이동한다.
 * 주사위를 굴린다.
 * 
*/

bool visit[101] = {false, };

int bfs(int v, vector<int> *e){
    // int distance = -1; // v에서 boundary 까지의 거리
    queue<int> q;
    int count = 1;

    q.push(v);
    visit[v] = true;
    int boundary = q.back();

    while(!q.empty()){
        bool rolled = false;
        int cur = q.front();
        q.pop();
        
        if(cur == 100) break;

        // check ladder or snake
        for(vector<int>::iterator itr = e[cur].begin() ; itr != e[cur].end() ; itr++){
            if(!visit[*itr]){
                q.push(*itr);
                visit[*itr] = true;}}

        // roll a die
        for(int i = 6 ; i >= 1 ; i--){
            if(cur+i <= 100){
                if(!visit[cur+i]){
                    q.push(cur+i);
                    visit[cur+i] = true;
                    // rolled = true;
                }
            }
        }
        if(cur == boundary){
            boundary = q.back();
            // if(rolled){
                count++;
            // }
        }
    }

    

    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // vector<int> *die;
    vector<int> edge[101];
    
    for(int i = 0 ; i < N+M ; i++){
        int x, y; cin >> x >> y;
        edge[x].push_back(y);
    }

    // for(int i = 0 ; i < M ; i++){
    //     int u, v; cin >> u >> v;
    //     edge[u].push_back(v);
    // }

    cout << bfs(1, edge);
    return 0;
}