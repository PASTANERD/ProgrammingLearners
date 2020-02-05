/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1744
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
    return (a < b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int numbs[N];

    int total = 0;
    int min = 0;
    int min_i = 0;
    int zero_i = 0;
    int max_i = 0;
    
    for(int i = 0 ; i < N ; i++) {
        cin >> numbs[i];
        total += numbs[i];
    }

    // sort(numbs, numbs+N);
    // int a = numbs[0] * numbs[1] + (total - numbs[0] - numbs[1]);
    // int b = numbs[N-2] * numbs[N-1] + (total - numbs[N-2] - numbs[N-1]);

    // cout << max({a, b, total}, comp);

    
    return 0;
}