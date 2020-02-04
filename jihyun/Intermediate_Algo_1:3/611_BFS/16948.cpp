
//
//  main.cpp
//  BJ 16948
//
//  Created by 지현 on 2020/02/04.
//  Copyright © 2020 지현. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

pair<int,int> mv[6] = {{-2,-1},{-2,1},{0,-2},{0,2},{2,-1},{2,1}};
int dist[201][201];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(dist, -1, sizeof(dist));
    int n;
    cin >> n;
    
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    
    queue<pair<int,int>> q;
    q.push({r1,c1});
    dist[r1][c1] = 0;
    
    while(!q.empty()){
        pair<int,int> cor = q.front(); q.pop();
        int c = cor.first, r = cor.second;
        for(int i=0; i<6; i++){
            int _c = c + mv[i].first;
            int _r = r + mv[i].second;
            
            if(_c < 0 || _c > 200 || _r < 0 || _r > 200) continue;
            
            if(dist[_c][_r] == -1){
                dist[_c][_r] = dist[c][r] + 1;
                q.push({_c,_r});
            }
        }
    }
    
    cout << dist[r2][c2];
}
