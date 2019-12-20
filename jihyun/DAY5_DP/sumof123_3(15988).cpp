/*
 problem : n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램
 input :  테스트 케이스의 개수 T와 정수 n
 output : 답을 1,000,000,009으로 나눈 나머지
 */

#include <iostream>

using namespace std;

int mod = 1000000009;
int d[1000001] = {0,1,2,4,};

int sub(int n){
    if(d[n] > 0)
        return d[n];
    d[n] = ((long long)sub(n-1) + sub(n-2) + sub(n-3)) % mod;
    return d[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int size;
    cin >> size;

    while(size--){
        int n;
        cin >> n;
        cout << sub(n) << '\n';
    }
}
