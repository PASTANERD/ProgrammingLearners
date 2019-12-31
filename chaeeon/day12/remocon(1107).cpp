/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1107
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

*incomplete

#include <iostream>
#include <string>
#define CURRENT 100

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    int M;
    cin >> N >> M;

    bool broken[M];
    fill_n(broken, M, false);
    int temp;
    for(int i = 0 ; i < M ; i++) {
        cin >> temp;
        broken[temp-1] = true;    
    }

    if(stoi(N) == CURRENT) cout << 0;
    else if(M == 10) cout << stoi(N)-CURRENT;
    else{

    }

    return 0;
}