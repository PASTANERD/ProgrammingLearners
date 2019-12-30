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