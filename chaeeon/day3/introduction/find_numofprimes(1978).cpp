/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1978
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
    for(int i = 2; i < n; i++) if(n%i == 0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    int din;
    int count = 0;
    for(int i = 0 ; i < N ; i++){
        cin >> din;
        if(isPrime(din)) count++;
    }
    cout << count << '\n';
    
    return 0;
}