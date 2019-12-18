#include <iostream>

using namespace std;

int d[1001] = {0,1,3,};

int sub(int n){
    
    if(d[n] > 0)
        return d[n];
    
    d[n] = (sub(n-1) + 2*sub(n-2)) % 10007;
    return d[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    cout << sub(n);
}
