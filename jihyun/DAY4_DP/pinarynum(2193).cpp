#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long d[91] = {0,1,};
    
    int n;
    cin >> n;
    
    for(int i=2; i<=n; i++){
        d[i]= d[i-1] + d[i-2];
    }
    
    cout << d[n];
}
