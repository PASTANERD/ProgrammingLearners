#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string n;
    long long b;
    cin >> n >> b;
    
    long long answer = 0;
    long long size = n.size();
    
    for(long long i = 0; i < size; i++){
        long long k;
        
        if(n[i]>='A')
            k = n[i]-'A' + 10;
        else
            k = n[i]-'0';
        
        answer += k*(pow(b,size-i-1));
    }

    cout << answer;
}
