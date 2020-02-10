
//1939
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int,int>> path[10001];
bool visited[10001] = {false,};
bool possible = false;

void check(int cur, int TO, int dist){
    if(cur == TO) {possible = true; return;}
    
    for(auto a : path[cur]){
        if(a.second < dist) continue;
        if(!visited[a.first]){
            visited[a.first] = true;
            check(a.first, TO, dist);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, max_dist = 0;
    cin >> N >> M;
    
    for(int i=0; i<M; i++){
        int from, to, dist;
        cin >> from >> to >> dist;
        path[from].push_back({to,dist});
        path[to].push_back({from,dist});
        max_dist = max(max_dist, dist);
    }
    
    int FROM, TO;
    cin >> FROM >> TO;
    
    int ans = 0;
    int left = 1;
    int right = max_dist;

    while(left<=right){
        int mid = (left+right)/2;
        possible = false;
        memset(visited,false,sizeof(visited));
        check(FROM, TO, mid);
        if(possible){
            left = mid + 1;
            ans = mid;
        }
        else
            right = mid - 1;
    }

    cout << ans;
}
