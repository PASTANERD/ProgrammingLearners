/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/9095
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <algorithm>

using namespace std;

int go(int n, int sum){
    if(n == sum) return 1;
    if(n < sum) return 0;
    int answer = 0;
    answer = go(n, sum+1) + go(n, sum+2) +go(n, sum+3);

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N;
    cin >> T;

    for(int i = 0 ; i < T ; i++){
        cin >> N;
        cout << go(N, 0) << '\n';
        // cout << N;
    }
    return 0;
}
