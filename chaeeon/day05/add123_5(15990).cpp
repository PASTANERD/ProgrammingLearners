/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/15990
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>

#define MAX_ARRAY 100000+1
#define DIVIDER 1000000009
using namespace std; 

long long **memo = new long long*[MAX_ARRAY];

long long sums(int N){
    return (memo[N][0] + memo[N][1] + memo[N][2]) % DIVIDER;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N;
    cin >> T;
    cin.ignore();

    for(int i = 0 ; i < MAX_ARRAY ; i++) {
        memo[i] = new long long[3];
        fill_n(memo[i], 3, -1);
    }

    memo[1][0] = 1;
    memo[1][1] = 0;
    memo[1][2] = 0;
    memo[2][0] = 0;
    memo[2][1] = 1;
    memo[2][2] = 0;
    memo[3][0] = 1;
    memo[3][1] = 1;
    memo[3][2] = 1;

    for(int i = 0 ; i < T ; i++){
        
        cin >> N;
        if(sums(N) > 0) cout << sums(N) << '\n';
        else{
            for(int j = 4; j <= N; j++){
                if(memo[j][0] == -1) {
                    memo[j][0] = (memo[j-1][1] + memo[j-1][2]) % DIVIDER;
                }
                if(memo[j][1] == -1) {
                    memo[j][1] = (memo[j-2][0] + memo[j-2][2]) % DIVIDER;   
                }
                if(memo[j][2] == -1){
                    memo[j][2] = (memo[j-3][1] + memo[j-3][0]) % DIVIDER;
                } 
            }
            cout << sums(N) << '\n';
        }
    }

    delete[] memo;
    
    return 0;
}