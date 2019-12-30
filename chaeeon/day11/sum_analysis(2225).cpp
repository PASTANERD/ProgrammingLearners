/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/2225
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#define MODULAR 1000000000

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    cin.ignore();

    unsigned int ** sa = new unsigned int*[N+1];
    for(int i = 0 ; i <= N ; i++){
        sa[i] = new unsigned int[K+1];
        fill_n(sa[i], K+1, 0);
        sa[i][1] = 1;
    }

    for(int j = 1 ; j <= K ; j++){
        for(int i = 0; i <= N; i++){    
            for(int k = 0; k <= i; k++){
                sa[i][j] += sa[i-k][j-1];
                sa[i][j] %= MODULAR;
            }
        }
    }
    cout << sa[N][K];
    return 0;
}

/**
 * N = i ; 
 * K = 1;
 * 0    0                               : 1
 * 1    1                               : 1
 * 2    2                               : 1
 * ...
 * 9    9                               : 1
 * 
 * K = 2;
 * 0    0+0                             : 1
 * 1    1+0, 0+1                        : 2
 * 2    2+0, 1+1, 0+2                   : 3
 * 3    3+0, 2+1, 1+2, 0+3              : 4
 * 4    4+0, 3+1, 2+2, 1+2, 0+4         : 5
 * ...
 * 9    9+0, 8+1, 7+2, ..., 1+8, 0+9    : 10
 * 
 * K = 3;
 * 1    1+0+0, 0+1+0, 0+0+1                         : 3
 * 2    2+0+0, 1+1+0, 1+0+1, 0+2+0, 0+1+1, 0+0+2    : 6
 * 
 * sa[N][K]: number of cases for N in cases of K;
 * sa[N][K] = sa[N][K-1] + sa[N-1][K-1] + .. +sa[0][K-1]
 * */