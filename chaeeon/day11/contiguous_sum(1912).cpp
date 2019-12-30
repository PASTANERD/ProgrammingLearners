/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1912
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int *A = new int[N+1];

    A[0] = 0;
    for(int i = 1 ; i <= N ; i++) cin >> A[i];
    
    int *csum = new int[N+1];
    csum[0] = 0;

    int maximum = -100000 * 1000;

    for(int i = 1 ; i <= N ; i++){
        csum[i] = max(csum[i-1] + A[i], A[i]);
        maximum = max(maximum, csum[i]);
    }

    cout << maximum << '\n';

    return 0;
}