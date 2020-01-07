#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<int> V[1001];
bool check[2000]= {false};

bool dfs(int v){
    check[v] = true;
    cout << v << " ";
    if(V[v].empty()) 
        return false;
    for(int x : V[v]){
        if(!check[x]){
            bool ans = dfs(x);
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m,v;
    cin >> n >> m >> v;
    for(int i=0; i<m; i++){
        int from,to;
        cin >> from >> to;
        V[from].push_back(to);
        V[to].push_back(from);
    }

    //dfs
    for(int i=1; i<n+1; i++){
        if(!V[i].empty())
            sort(V[i].begin(), V[i].end());
    }
    bool ans = dfs(v);
    cout << "\n";


    //bfs
    queue<int> q;
    fill_n(check, 2000, false);
    q.push(v);

    while(!q.empty()){
        int element = q.front();
        check[element] = true;
        q.pop();
        cout << element << " ";

        for(int x : V[element]){
            if(!check[x]){
                q.push(x);
                check[x] = true;
            }
        }
    }
    cout << "\n";

    return 0;
}