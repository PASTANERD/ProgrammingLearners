
//
//  main.cpp
//  BJ 1790
//
//  Created by 지현 on 2020/02/04.
//  Copyright © 2020 지현. All rights reserved.
//

#include <iostream>

using namespace std;

long long calc(int n){
    long long length = 0;
    for(int start=1, l=1; start<=n; start*=10, l++){
        int end = start*10-1;
        if(end > n)
            end = n;
        length += (long long)(end - start + 1)*l;
    }
    return length;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long k;
    cin >> n >> k;
    
    if(calc(n) < k){
        cout << -1;
        return 0;
    }
    
    int left = 1;
    int right = n;
    int ans = 0;
    
    while(left<=right){
        int mid = (left+right)/2;
        long long length = calc(mid);
        if(length < k)
            left = mid + 1;
        else{
            ans = mid;
            right = mid - 1;
        }
    }
    string s = to_string(ans);
    long long l = calc(ans);
    cout << s[s.length()-(l-k)-1];
}
