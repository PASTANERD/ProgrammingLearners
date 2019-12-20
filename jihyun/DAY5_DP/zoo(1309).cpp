#include <iostream>

using namespace std;

int mod = 9901;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int size;
    cin >> size;
    
    //d[i][j] : n번 줄에 배치 안함 (j=0) / 왼쪽에 배치 (j=1) / 오른쪽 배치 (j=2)
    int d[100001][3] = {{0,},};
    
    d[1][0] = 1;
    d[1][1] = 1;
    d[1][2] = 1;
    
    for(int i=2; i<=size; i++){
        d[i][0] = (d[i-1][0] + d[i-1][1] + d[i-1][2]) % mod;
        d[i][1] = (d[i-1][0] + d[i-1][2]) % mod;
        d[i][2] = (d[i-1][0] + d[i-1][1]) % mod;
    }
    
    cout << (d[size][0] + d[size][1] + d[size][2]) % mod;
}
