//input : 첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.
//output : 첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.


#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int d[101][10] ={{0,}};
    int k = 1000000000;
    
    int n;
    cin >> n;
    
    for(int i=1; i<=9; i++)
        d[1][i] = 1;
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            d[i][j] = 0;
            if(j-1 >= 0) d[i][j] += d[i-1][j-1];
            if(j+1 <= 9) d[i][j] += d[i-1][j+1];
            d[i][j] %= k;
        }
    }
    
    long long ans = 0;
    for(int i=0; i<=9; i++){
        ans += d[n][i];
    }
    ans %= k;
    
    cout << ans;
}

