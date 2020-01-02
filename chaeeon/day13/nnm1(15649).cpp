/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/15649
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>

using namespace std;

bool used[10]; int a[10];
int go(int index, int n, int m){
    if(index == m){
        for(int i = 0 ; i < m ; i++) cout << a[i] << ' ';
        cout << '\n';
    }
    else{
        for(int i = 1 ; i <= n ; i++){
            if(used[i]) continue;
            else{
                used[i] = true;
                a[index] = i;
                go(index+1, n, m);
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

    fill_n(used, N+1, false);
    go(0, N, M);
    
    return 0;
}