/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/16947
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int *visit;
int *d;
vector<int> cycle;

void bfs(int v, vector<int> *e){
    queue<int> q;
    int current = 0;
    
    q.push(v);
    while(!q.empty()){
        current = q.front();
        for(vector<int>::iterator next = e[current].begin() ; next != e[current].end() ; next++){
            if(d[*next] < 0) {
                q.push(*next);
                d[*next] = d[current]+1;
            }
        }
        q.pop();
    }
}

int cycle_finder(int v, int from, vector<int> *e){
    if(visit[v] == -1) return v;
    visit[v] = -1;
    
    for(vector<int>:: iterator next = e[v].begin() ; next != e[v].end() ; next++){
        if(*next != from){
            int check = cycle_finder(*next, v, e);
            if(check > 0){
                visit[v] = 2;
                cycle.push_back(v);
                if(check == v) return -2;
                else return check;
            }
        }
    }
    return -2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<int> adj[N+1];
    for(int i = 0 ; i < N ; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    visit = new int[N+1];
    fill_n(visit, N+1, 0);

    cycle_finder(1, 1, adj);

    d = new int[N+1];
    fill_n(d, N+1, -1);
    for(vector<int>::iterator itr = cycle.begin() ; itr != cycle.end() ; itr++){
        d[*itr] = 0;
    }
    for(vector<int>::iterator itr = cycle.begin() ; itr != cycle.end() ; itr++){
        bfs(*itr, adj);
    }
    for(int i = 1 ; i <= N ; i++) cout << d[i] << " ";

    return 0;
}
