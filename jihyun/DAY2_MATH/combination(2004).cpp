#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, m;
    cin >> n >> m;
    
    long long ans2 = 0, ans5 = 0;
    
    for(long long i = 2; i <= n; i*=2){
        ans2 += n/i;
    }
    
    for(long long i = 5; i <= n; i*=5){
        ans5 += n/i;
    }
    
    for(long long i = 2; i <= m; i*=2){
        ans2 -= m/i;
    }

    for(long long i = 5; i <= m; i*=5){
        ans5 -= m/i;
    }

    for(long long i = 2; i <= n-m; i*=2){
        ans2 -= (n-m)/i;
    }

    for(long long i = 5; i <= n-m; i*=5){
        ans5 -= (n-m)/i;
    }

    if(ans2<0)  ans2 = 0;
    if(ans5<0)  ans5 = 0;
    
    (ans2 < ans5) ? cout << ans2 : cout << ans5;
}

