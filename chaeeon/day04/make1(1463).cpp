/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1463
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

/*
 *  D(N): Minimum number of calculations to make 1
 *  D(N) = 1 + D(N/3)
 *  D(N) = 1 + D(N/2)
 *  D(N) = 1 + D(N-1)
 *  --> D(N) = min(D(N/3), D(N/2), D(N-1))
 */

#include <iostream>

using namespace std;

int *memo;
int MinCal(int N){
    if(N == 1) return 0;
    if(memo[N] > 0) return memo[N];
    int temp;
    memo[N] = 1 + MinCal(N-1);
    if(N%2 == 0){
        temp = 1 + MinCal(N/2);
        if(temp < memo[N]) memo[N] = temp;
    }
    if(N%3 == 0){
        temp = 1 + MinCal(N/3);
        if(temp < memo[N]) memo[N] = temp;
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

    memo = (int*)calloc(N+1,sizeof(int));
    for(int i = 0; i <= N ; i++) memo[i] = 0;

    int answer = MinCal(N);
    cout << answer << '\n';

    free(memo);
    
    return 0;
}