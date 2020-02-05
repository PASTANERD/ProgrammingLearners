/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/11728
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

    int N, M;
    cin >> N >> M;

    vector<int> ns(N);
    vector<int> ms(M);
    for(int i = 0 ; i < N ; i++) cin >> ns[i];
    for(int i = 0 ; i < M ; i++) cin >> ms[i];

    ns.insert(ns.end(), ms.begin(), ms.end());
    sort(ns.begin(), ns.end());

    for(int a : ns){
        cout << a << ' ';
    }


    return 0;
}