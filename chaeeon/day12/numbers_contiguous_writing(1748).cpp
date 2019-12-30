/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1748
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

    unsigned int N;
    cin >> N;

    unsigned int len = 0;

    int k = 1;
    for(int i = 1 ; i <= 100000000 ; i *= 10){
        if(N >= i*10) len += ((i*10 - 1) - i + 1)*k;
        else {
            len += (N - i + 1)*k;
            break;    
        }
        k++;
    }

    cout << len;
    return 0;
}