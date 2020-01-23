/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/11047
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    
    int coins[N];
    for(int i = 0 ; i < N ; i++) cin >> coins[i];

    int count = 0;
    for(int i = 0 ; i < N ; i++){
        count = count + K/coins[N-1-i];
        K %= coins[N-1-i];
    }

    cout << count;
    return 0;
}