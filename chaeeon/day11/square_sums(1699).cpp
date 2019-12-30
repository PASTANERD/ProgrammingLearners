/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1699
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/
/**
 * mss[N]: Minimum cases for N
 * mss[N] = min(mss[N], mss[N-i*i] + 1)
 * */
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int *mss = new int[N+1];

    fill_n(mss, N+1, 0);

    for(int i = 1 ; i <= N ; i++){
        mss[i] = i;
        for(int j = 1 ; j*j <= i ; j++){
            if(mss[i] > mss[i-j*j] + 1) mss[i] = mss[i-j*j] + 1;
        }
    }
    
    cout << mss[N];

    return 0;
}