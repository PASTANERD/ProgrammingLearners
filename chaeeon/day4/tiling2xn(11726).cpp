/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/11726
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

/*
 *  rec(N): Number of rectangles to fill 2 x N rectangle with (2x1) rectangle and (1x2) rectangle
 *  rec(N) = rec(N-1) + 1 // (2x1)
 *  rec(N) = rec(N-2) + 1 // (1x2)
 */

#include <iostream>

using namespace std;

int *memo;
int nrec(int N){
    if(N == 0) return 1;
    if(N == 1) return 1;
    if(memo[N] > 0) return memo[N];
    else{
        memo[N] = (nrec(N-1) + nrec(N-2)) % 10007;
    }
    return memo[N];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    memo = new int[N+1];
    for(int i = 0; i <= N ; i++) memo[i] = 0;

    cout << nrec(N) << '\n';

    return 0;
}