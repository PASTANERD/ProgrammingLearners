/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/2875
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    int N_2 = N / 2;
    int teams = min(N_2, M);
    int reservoir = N+M-teams*3;
    int diff = K - reservoir;

    if(diff <= 0 ) cout << teams;
    else{
        cout << (teams - ((diff-1)/3 + 1));
    }
    
    return 0;
}