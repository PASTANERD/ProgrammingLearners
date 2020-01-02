/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/6064
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    int M, N, x, y, Y, k;
    bool pass = false;

    for(int i = 0 ; i < T ; i++){
        cin >> M >> N >> x >> y;
        for(int k = x ; k < M*N; k+=M){
            Y = (k-1)%N+1;
            if(Y == y){
                cout << k << '\n';
                pass = true;
                break;
            }
        }
        if(!pass) cout << -1 << '\n';
        pass = false;
    }
    return 0;
}