/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/2873
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    // int board[R][C];
    int mino = 1000;
    int mi, mj;
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            int temp;
            cin >> temp;
            // cin >> board[i][j];
            if(mino >= temp && i != 0 && i != R-1 && j != 0 && j != C-1){
                mino = tmep;
                mi = i; mj = j;
            }
        }
    }

    string answer;
    
    if((R%2) == 1){
        for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++){
                if(j == C-1) answer.push_back('D');//cout << 'D';
                else if((i%2)==0) answer.push_back('R');//cout << 'R'
                else answer.push_back('L');//cout << 'L';
            }
        }
        answer.pop_back();
    }
    else if((C%2) == 1){
        for(int i = 0 ; i < C ; i++){
            for(int j = 0 ; j < R ; j++){
                if(j == R-1) answer.push_back('R');//cout << 'D';
                else if((i%2)==0) answer.push_back('D');//cout << 'D'
                else answer.push_back('U');//cout << 'U';
            }
        }
        answer.pop_back();
    }
    else{
        // for(int i = 0 ; i < C ; i++){
        //     for(int j = 0 ; j < R ; j++){
        //         if()
        //         if(j == R-1) answer.push_back('R');//cout << 'D';
        //         else if((i%2)==0) answer.push_back('D');//cout << 'D'
        //         else answer.push_back('U');//cout << 'U';
        //     }
        // }
        // answer.pop_back();
    }

    cout << answer;
    return 0;
}