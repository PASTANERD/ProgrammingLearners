/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1182
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <cmath>

using namespace std;

int N, S;
int go(int sum, int*sequence, int index){
    if(index == N){
        if(sum == S) return 1;
        else return 0;
    } 
    return go(sum+sequence[index], sequence, index+1) + go(sum, sequence, index+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;

    int sequence[N];

    for(int i = 0 ; i < N ; i++) cin >> sequence[i];
    
    int answer = 0;
    if(S == 0){
        answer = go(0, sequence, 0) - 1;
    }
    else answer = go(0, sequence, 0);

    cout << answer;

    return 0;
}
