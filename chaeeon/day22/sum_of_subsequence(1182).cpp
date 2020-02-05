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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;

    int sequence[N];

    for(int i = 0 ; i < N ; i++) cin >> sequence[i];
    
    int answer = 0;
    for(int i = 1 ; i < (1 << N) ; i++){
        int sum = 0;
        for(int j = 0 ; j < N ; j++){
            if(i&(1<<j)) {
                sum += sequence[j];
            }
        }
        if(sum == S) answer++;
    }

    cout << answer;
    return 0;
}
