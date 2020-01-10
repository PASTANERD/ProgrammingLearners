#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,int>> *tree;
int MAX = 0, t;

void DFS(int prev, int cur, int sum){
    if(sum > MAX){
        MAX = sum; t = cur;}
    
    for(pair<int, int> i : tree[cur])
        if(i.first!=prev)
            DFS(cur, i.first, sum+i.second);
}

int main(){
    int v;
    cin >> v;
    tree = new vector<pair<int,int>>[v+1];
    
    for(int i=0; i<v; i++){
        int I;
        cin >> I;
        while(1){
            int YOU, dist;
            cin >> YOU;
            if(YOU == -1) break;
            cin >> dist;
            tree[I].push_back({YOU, dist});
        }
    }
    
    DFS(0,1,0);
    DFS(0,t,0);
    
    cout << MAX;
}
