#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    int *d = new int[n+1];      // d[n] : n을 제곱수의 합으로 표현할 때 그 항의 최소 개수
    
    for(int i=1; i<=n; i++){
        d[i] = i;               //max of answer is i
        
        for(int j=1; j*j <= i; j++){
            if(d[i] > d[i-j*j] + 1)
                d[i] = d[i-j*j] + 1;
        }
    }

    cout << d[n];
}
