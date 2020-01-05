/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/2156
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

/*
 *  best(N):    best cases to have maximum wines for number of N wines
 *  best(N) = max(cases[N][0], cases[N][1], cases[N][2]) 
 *  cases[N][C]: 
 *  cases[N][0] = max(cases[N-1], cases[N-1][1], cases[N-1][2])
 *  cases[N][1] = cases[N-1][0] + wine[N]
 *  cases[N][2] = cases[N-1][1] + wine[N]
 *  
 */

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    int **cases = new int*[N+1];
    int wine[N+1];
    for(int i = 1 ; i <= N ; i++){
        cases[i] = new int[3];
        cin >> wine[i];
    }

    cases[1][0] = 0;
    cases[1][1] = wine[1];
    cases[1][2] = 0;
    for(int i = 2 ; i <= N ; i++){
        cases[i][0] = max(max(cases[i-1][0], cases[i-1][1]), cases[i-1][2]);
        cases[i][1] = cases[i-1][0] + wine[i];
        cases[i][2] = cases[i-1][1] + wine[i];
    }

    cout << max(max(cases[N][0], cases[N][1]), cases[N][2]) << '\n';
    return 0;
}