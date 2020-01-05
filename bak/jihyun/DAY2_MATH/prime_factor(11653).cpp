#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    cin >> n;
    int p = 2;
    
    while(n!=1){
        if(n % p == 0){
            cout << p << '\n';
            n /= p;
        }
        else
            p++;
    }
}

