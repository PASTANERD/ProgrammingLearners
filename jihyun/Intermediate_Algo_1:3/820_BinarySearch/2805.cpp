
//
//  main.cpp
//  BJ 2805
//
//  Created by 지현 on 2020/02/04.
//  Copyright © 2020 지현. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long m;
    cin >> n >> m;
    long long tree[n];
    
    for(int i=0;i<n;i++)
        cin >> tree[i];
    sort(tree, tree+n);
    
    long long ans = 0;
    long long left = 0;
    long long right = tree[n-1];
    
    while(left <= right){
        long long mid = (left+right)/2;
        long long sum = 0;
        
        for(auto t : tree)
            sum += (t-mid > 0 ? t-mid : 0);
        
        if(sum >= m){
            left = mid + 1;
            ans = mid;
        }
        else
            right = mid - 1;
    }
    
    cout << ans;
}
