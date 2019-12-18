/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/11727
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

/*
 *  rec(N): Number of rectangles to fill 2 x N rectangle with (2x1) rectangle, (1x2) rectangle, (2x2) rectangle
 *  rec(N) = rec(N-1) + 1 // (2x1)
 *  rec(N) = rec(N-2) + 1 // (1x2)
 */

#include <iostream>

using namespace std;

int *memo;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    memo = new int[N+1];
    for(int i = 0; i <= N ; i++) memo[i] = 0;
 
    memo[0] = 1;
    memo[1] = 1;
    for(int i = 2 ; i <= N ; i++){
        memo[i] = memo[i-2]*2 + memo[i-1];
        memo[i] %= 10007;
    }
    cout << memo[N] << '\n';

    return 0;
}