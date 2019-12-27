/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/2193
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
    
    unsigned long *pinary = new unsigned long[N];

    pinary[0] = 1;
    pinary[1] = 1;
    for(int i = 2 ; i < N; i++) pinary[i] = pinary[i-1] + pinary[i-2];
    
    cout << pinary[N-1];

    return 0;
}