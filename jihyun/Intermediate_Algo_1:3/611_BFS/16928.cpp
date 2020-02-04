
//
//  main.cpp
//  BJ 16928
//
//  Created by 지현 on 2020/02/04.
//  Copyright © 2020 지현. All rights reserved.
//

#include <iostream>
#include <queue>
#define next _next
using namespace std;

int dist[101] = {0};
int next[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<101; i++)
        next[i] = i;
        
    for(int i=0; i<n+m; i++){
        int x, y;
        cin >> x >> y;
        next[x] = y;
    }
    
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i=1; i<=6; i++){
            int cur = x+i;
            if(cur > 100) continue;
            cur = next[cur];
            if(dist[cur]==0){
                dist[cur] = dist[x] + 1;
                q.push(cur);
            }
        }
    }
    
    cout << dist[100];
}
