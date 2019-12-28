/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/9095
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

int *memo;
int nums(int N){
    if(N == 0) return 1;
    if(memo[N] > 0) return memo[N];
    memo[N] = nums(N-1);
    if(N > 1) memo[N] += nums(N-2);
    if(N > 2) memo[N] += nums(N-3);
    return memo[N];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    memo = new int[11];
    fill_n(memo, 11, 0);

    int cases;
    for(int i = 0 ; i < N ; i++){
        cin >> cases;
        cout << nums(cases) << '\n';
    }

    delete memo;    

    return 0;
}