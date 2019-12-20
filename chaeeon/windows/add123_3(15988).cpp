/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/15988
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

/*
 *  nums(N): number of cases make N with combinations of 1, 2 and 3
 *  nums(N) = nums(N-1) + nums(N-2) + nums(N-3)
 */

#include <iostream>

using namespace std;

unsigned int *memo;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    unsigned int cases;
    for(int i = 0 ; i < N ; i++){
        cin >> cases;
        memo = new unsigned int[cases+1];
        for(int j = 0; j <= cases ; j++) memo[j] = 0;

        memo[0] = 1;
        memo[1] = 1;
        if(cases > 1) memo[2] = memo[0] + memo[1];
        for(int k = 3; k <= cases; k++){
            memo[k] = (memo[k-1] + memo[k-2] + memo[k-3]) % 1000000009;
        }
        cout << memo[cases] << '\n';

        delete memo;
    }
    return 0;
}