/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/15650
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>

using namespace std;

int a[10];
int go(int index, int selected, int n, int m){
    if(selected == m){
        for(int i = 0 ; i < m ; i++) cout << a[i] << ' ';
        cout << '\n';
        return 0;
    }
    else{
        if(index > n) return 0;
        a[selected] = index;
        go(index+1, selected+1, n, m);
        a[selected] = 0;
        go(index+1, selected, n, m);
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    go(1, 0, N, M);
    
    return 0;
}

/**
 *  1 2 3 4 5 ..
 * O  O
 * X  X
 * 
 *  자리 1 2 3  --> selected
 *  수   2 5 6 --> index
 * */
