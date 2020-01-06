/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1929
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>

using namespace std;

bool isPrime(int n){
    if(n < 2){
        return false;
    }
    for(int i = 2; i*i <= n; i++) if(n%i == 0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;
    cin.ignore();

    for(int i = A ; i <= B ; i++){
        if(isPrime(i)) cout << i << '\n';
    }
    
    return 0;
}