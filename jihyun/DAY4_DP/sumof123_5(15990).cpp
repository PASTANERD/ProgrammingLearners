//d[i][j] = i를 1,2,3의 합으로 나타내는 방법의 수, 마지막에 사용한 수는 j

#include <iostream>

using namespace std;

int d[100001][4] = {{0,0,0,0},{0,1,0,0},{0,0,1,0},{0,1,1,1},};
int ans[100001] = {0,1,1,3,};
int k = 1000000009;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int size;
    cin >> size;
    
    while(size--){
        int n;
        cin >> n;
        
        if(ans[n] > 0){
            cout << ans[n] << '\n';
            continue;
        }
            
        for(int i = 4; i <= n; i++){
            d[i][1] = ((long long)d[i-1][2] + d[i-1][3]) % k;
            d[i][2] = ((long long)d[i-2][1] + d[i-2][3]) % k;
            d[i][3] = ((long long)d[i-3][1] + d[i-3][2]) % k;
        
            ans[i] = ((long long)d[i][1] + d[i][2] + d[i][3]) % k;
        }
        
        cout << ans[n] << '\n';
    }
}

