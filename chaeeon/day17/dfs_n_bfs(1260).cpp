/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/14889
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool *visit;

void bfs(int v, vector<int> *e){
    queue<int> *q = new queue<int>();
    int current = 0;
    
    q->push(v);

    while(!q->empty()){
        current = q->front();
        visit[current] = true;
        cout << current << " ";
        for(vector<int>::iterator next = e[current].begin() ; next != e[current].end() ; next++){
            if(!visit[*next]) q->push(*next);
        }
        q->pop();
    }
}

void dfs(int v, vector<int>* e){
    visit[v] = true;
    cout << v << " ";
    for(vector<int>::iterator next = e[v].begin() ; next != e[v].end() ; next++){
        if(!visit[*next]) dfs(*next, e);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, V;
    cin >> N >> M >> V;
    vector<int> *adjacent;

    visit = new bool[N+1];
    adjacent = new vector<int>[N+1];

    for(int i = 0 ; i < M ; i++){
        int x, y;
        cin >> x >> y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }
    
    // need to sort edges
    for(int i = 1 ; i <= N ; i++) sort(adjacent[i].begin(), adjacent[i].end());
    
    // dfs
    fill_n(visit, N, false);
    dfs(V, adjacent);

    cout << '\n';
    
    // bfs
    fill_n(visit, N, false);
    bfs(V, adjacent);

    return 0;
}
