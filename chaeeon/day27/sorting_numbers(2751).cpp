/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/2751
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> numbs(N);
    for(int i = 0 ; i < N ; i++) cin >> numbs[i];

    sort(numbs.begin(), numbs.end());

    for(int a : numbs){
        cout << a << ' ';
    }


    return 0;
}