/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/15652
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <algorithm>

using namespace std;

int base[10];
bool used[10];
int a[10];
int go(int index, int started, int n, int m){
    if(index == m){
        for(int i = 0 ; i < m ; i++) cout << a[i] << ' ';
        cout << '\n';
    }
    else{
        for(int i = started ; i < n ; i++){
            if(used[i]) continue;
            else{
                used[i] = true;
                a[index] = base[i];
                go(index+1, i, n, m);
                used[i] = false;
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    fill_n(used, 10, false);
    for(int i = 0 ; i < N ; i++) cin >> base[i];
    sort(base, base+N);
    go(0, 0, N, M);
    
    return 0;
}