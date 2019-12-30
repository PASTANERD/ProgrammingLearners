
/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/2225
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

    int memo = new int[N+1];

    memo[1] = K;
    memo[2] = N+1;

    for(int i = 3; i <=N ; i++){
        memo[N] = memo[N-1] + memo[N-2];
    }

    if(K == 1) cout << 1;
    else cout << memo[N];
    return 0;
}