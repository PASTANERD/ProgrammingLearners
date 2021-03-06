
//  main.cpp
//  BJ 1654
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
    
    int k, n;
    cin >> k >> n;
    int have[k];
    
    for(int i=0; i<k; i++)
        cin >> have[i];
    
    sort(have, have+k);
    
    long long ans = 0;
    long long left = 1;
    long long right = have[k-1];
    
    while(left<=right){
        long long mid = (left+right)/2;
        int sum = 0;
        for(auto t : have)
            sum += t/mid;
        if(sum >= n){
            left = mid + 1;
            ans = mid;
        }
        else{
            right = mid - 1;
        }
    }
    cout << ans;
}
