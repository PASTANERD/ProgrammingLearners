/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/3085
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/
*incomplete
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_candy(){

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string board[N];
    for(int i = 0 ; i < N ; i++) {
        cin >> board[i];

        // cout << board[i] << '\n';
    }
    cout << "\n\n";
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }


    return 0;
}