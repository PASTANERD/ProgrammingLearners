
//2251
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
int MAX[3];
bool visited[201][201] = {{false,},};
queue<tuple<int,int,int>> q;
int to[6] = {0,0,1,1,2,2};
int from[6] = {1,2,0,2,0,1};

bool is_pos(int next[3]){
    for(int i=0; i<3; i++){
        if(next[i] < 0 || next[i] > MAX[i])
            return false;
    }

    if(visited[next[0]][next[1]])
        return false;
    
    return true;
}

void push(int next[3]){
    visited[next[0]][next[1]] = true;
    q.push({next[0],next[1],next[2]});
}

int main(){
    cin >> MAX[0] >> MAX[1] >> MAX[2];
    q.push({0,0,MAX[2]});
    visited[0][0] = true;
    vector<int> ans;
    
    while(!q.empty()){
        tuple<int,int,int> t;
        t = q.front();
        q.pop();
        int cur[3];
        tie(cur[0],cur[1],cur[2]) = t;
        
        if(cur[0] == 0) ans.push_back(cur[2]);
        
        for(int k=0; k<6; k++){
            int next[3] = {cur[0],cur[1],cur[2]};
            next[from[k]] = 0;
            next[to[k]] = cur[to[k]] + cur[from[k]];
            if(is_pos(next)) push(next);
            next[from[k]] = cur[from[k]] - (MAX[to[k]]-cur[to[k]]);
            next[to[k]] = MAX[to[k]];
            if(is_pos(next)) push(next);
        }
    }
    
    sort(ans.begin(), ans.end());
    for(auto i : ans){
        cout << i << ' ';
    }
}
