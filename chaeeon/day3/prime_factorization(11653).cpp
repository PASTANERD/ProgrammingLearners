/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/11653
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

    int i = 2;
    while(N > 1){
        if(N%i == 0){
            cout << i << '\n';
            N = N / i;
        }
        else i++;
    }
    
}