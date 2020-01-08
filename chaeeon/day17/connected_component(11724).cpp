/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/14889
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>

using namespace std;

bool *visit;
void dfs(int v, vector<int>* e){
    visit[v] = true;
    for(vector<int>::iterator next = e[v].begin() ; next != e[v].end() ; next++){
        if(!visit[*next]) dfs(*next, e);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> *adjacent;

    visit = new bool[N+1];
    adjacent = new vector<int>[N+1];

    for(int i = 0 ; i < M ; i++){
        int x, y;
        cin >> x >> y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }
    
    // dfs
    int count = 0;
    fill_n(visit, N+1, false);
    for(int i = 1 ; i <= N ; i++){
        if(!visit[i]){
            dfs(i, adjacent);
            count++;
        }
    }
    
    cout << count;

    return 0;
}
