//1260
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

bool check[1001] = {false,};
vector<int> ar[1001];
queue<int> q;

void dfs(int x){
    check[x] = true;
    cout << x << ' ';
    for(int i=0; i<ar[x].size(); i++){
        int temp = ar[x][i];
        if(!check[temp])
            dfs(temp);
    }
}

void bfs(int x){
    check[x] = true;
    q.push(x);  cout << x << ' ';
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i=0; i<ar[temp].size(); i++){
            int y = ar[temp][i];
            if(!check[y]){
                check[y] = true;
                q.push(y);  cout << y << ' ';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
   
    int n, m, v;
    cin >> n >> m >> v;
    
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    
    for(int i=0; i<n; i++)
        if(ar[i].size() != 0)
            sort(ar[i].begin(), ar[i].end());
    
    dfs(v);
    cout << '\n';
    fill_n(check, n+1, false);
    bfs(v);
}
