#include <iostream>

using namespace std;

int mod = 10007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //d[i][j] : 길이가 i이고 마지막 숫자가 j인 오르막수 개수
    int d[1001][10] = {{0,},};
    
    int n;
    cin >> n;
    
    for(int i=0; i<10; i++)
        d[1][i] = 1;
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<=j; k++){
                d[i][j] += d[i-1][k];
                d[i][j] %= mod;
            }
        }
    }
    
    long long ans = 0;
    
    for(int i=0; i<10; i++)
        ans += d[n][i];
    
    ans %= mod;
    
    cout << ans;
}
