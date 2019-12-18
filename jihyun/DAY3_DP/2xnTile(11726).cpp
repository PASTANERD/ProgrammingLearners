#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int d[1001] = {0,1,2,};
    
    for(int i = 3; i <= n; i++){
        d[i] = (d[i-1] + d[i-2]) % 10007;
    }
    
    cout << d[n];
}
