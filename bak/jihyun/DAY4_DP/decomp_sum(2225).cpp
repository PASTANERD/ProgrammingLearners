/*
 problem : 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램
 input : 두 정수 N(1 ≤ N ≤ 200), K(1 ≤ K ≤ 200)
 output : 답을 1,000,000,000으로 나눈 나머지
 */

#include <iostream>

using namespace std;

int mod = 1000000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long d[201][201];
    
    int n, k;
    cin >> n >> k;

    d[0][0] = 1LL;
    
    for(int i=1; i<=k; i++){
        for(int j=0; j<=n; j++){
            d[i][j] = 0;
            for(int l=0; l<=j; l++){
                d[i][j] += d[i-1][j-l];
                d[i][j] %= mod;
            }
        }
    }
    
    cout << d[k][n];
}
