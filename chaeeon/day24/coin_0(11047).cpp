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
    int cursor = N-1;
    while(K != 0){
        if(coins[cursor] > K) cursor--;
        else{
            K -= coins[cursor];
            count++;
        }
    }

    cout << count;
    return 0;
}