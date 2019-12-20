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
incompleted

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    unsigned int *memo = new unsigned int[4];

    unsigned int cases;
    unsigned int index = 0;
    for(int i = 0 ; i < N ; i++){
        cin >> cases;
        // cout << "case: " << cases << '\n';
        for(int j = 0; j <= cases ; j++) memo[j] = 0;
        memo[0] = 1;
        memo[1] = 1;
        if(cases > 1) memo[2] = memo[0] + memo[1];
        for(int k = 3; k <= cases; k++){
            memo[k%4] = (memo[(k-1)%4] + memo[(k-2)%4] + memo[(k-3)%4]) % 1000000009;
            // cout << memo[k%4] << " ";
            index = k%4;
        }
        cout << memo[index] << '\n';
    }
    
    delete memo;
    return 0;
}