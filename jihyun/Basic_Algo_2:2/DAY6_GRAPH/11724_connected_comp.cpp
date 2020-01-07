//11724
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool check[1001] = {false,};
vector<int> ar[1001];

void dfs(int x){
    check[x] = true;
    for(int i=0; i<ar[x].size(); i++){
        int temp = ar[x][i];
        if(!check[temp])
            dfs(temp);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
   
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    
    int cnt = 0; check[0] = true;
    while(1){
        auto k = find(check, check+n+1, false);
        if(k == check+n+1)
            break;
        int index = distance(check, k);
        dfs(index);
        cnt ++;
    }
    cout << cnt;;
}
