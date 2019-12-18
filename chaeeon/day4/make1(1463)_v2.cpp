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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    int *memo = (int*)malloc(sizeof(int)*(N+1));
    int temp;

    memo[1] = 0;
    for(int i = 2; i <= N ; i++){
        memo[i] = 1 + memo[i-1];
        if(i%2 == 0){
            temp = 1 + memo[i/2];
            if(temp < memo[i]) memo[i] = temp;
        }
        if(i%3 == 0){
            temp = 1 + memo[i/3];
            if(temp < memo[i]) memo[i] = temp;
        }
    }

    cout << memo[N] << '\n';
    
    return 0;
}