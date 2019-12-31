/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1476
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int E, S, M;
    cin >> E >> S >> M;

    int e = 1, s = 1, m = 1;
    int years = 1;
    while(true){
        if(e == E && s == S && m == M) break;
        e += 1;
        s += 1;
        m += 1;

        if(e > 15) e %= 15;
        if(s > 28) s %= 28;
        if(m > 19) m %= 19;

        years++;
    }    
    
    cout << years;

    return 0;
}