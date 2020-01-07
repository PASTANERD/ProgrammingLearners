#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> V[1001];
bool check[2000]= {false};

bool dfs(int v){
    check[v] = true;
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

    int n,m;
    cin >> n >> m;
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

    int components = 0;
    for(int i=1; i<=n; i++){
        if(!check[i]){
            bool ans = dfs(i);
            components++;
        }   
    }
    
    cout << components << "\n";


    return 0;
}