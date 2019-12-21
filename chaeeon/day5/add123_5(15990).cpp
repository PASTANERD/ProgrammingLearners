/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/15990
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
int nums(int N, int adj){
    if(memo[N] > 0) return memo[N];
    if(adj == -1){
        // if(N <= 0) return 0;
        // if(N == 1) return 1;
        // if(N == 2) return 1;
        memo[N] = nums(N-1, 1) + nums(N-2, 2) + nums(N-3, 3);
    }
    else if(adj == 1){
        if(N <  0) return 0;
        if(N == 0) return 1;
        if(N > 0) memo[N] = nums(N-2, 2) + nums(N-3, 3);
    }
    else if (adj == 2){
        if(N <  1) return 0;
        if(N == 1) return 1;
        if(N > 1) memo[N] = nums(N-1, 1) + nums(N-3, 3);
    }
    else{
        if(N <  2) return 0;
        if(N == 2) return 1;
        if(N > 2) memo[N] = nums(N-1, 1) + nums(N-2, 2);
    }
    return memo[N] % 1000000009;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    int cases;
    for(int i = 0 ; i < N ; i++){
        cin >> cases;
        memo = new int[cases+1];
        for(int j = 0; j <= cases ; j++) memo[j] = 0;

        cout << nums(cases, -1) << '\n';

        delete memo;
    }
    

    return 0;
}