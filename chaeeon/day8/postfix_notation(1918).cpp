/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1918
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

    int *triangle = new int[(N+1)*N/2];

    for(int i = 0 ; i < (N+1)*N/2 ; i++){
        cin >> triangle[i];
        cout << triangle[i] << ' ';
    }


    return 0;
}