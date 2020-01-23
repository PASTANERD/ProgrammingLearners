/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1080
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <algorithm>

using namespace std;

// void flip(int** A, int i, int j){
//     for(int di = 0 ; di < 3 ; di++){
//         for(int dj = 0 ; dj < 3 ; dj++){
//             A[i+di][i+dj] = A[i+di][i+dj] ^ 1;
//         }
//     }
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int A[N][M];
    int B[N][M];
    for(int i = 0 ; i < N ; i++){
        string temp;
        cin >> temp;
        for(int j = 0 ; j < temp.length() ; j++){
            A[i][j] = temp[j];
        }
    }
    for(int i = 0 ; i < N ; i++){
        string temp;
        cin >> temp;
        for(int j = 0 ; j < temp.length() ; j++){
            B[i][j] = temp[j];
        }
    }

    bool check = true;
    int count = 0;
    for(int i = 0; i < N-2 ; i++){
        for(int j = 0 ; j < M-2 ; j++){
            if(A[i][j] != B[i][j]){
                for(int di = 0 ; di < 3 ; di++){
                    for(int dj = 0 ; dj < 3 ; dj++){
                            A[i+di][i+dj] = A[i+di][i+dj] ^ 1;
                    }
                }
                // if(i+2 >= N || j+2 >= M) continue;
                // else{
                // flip(A,i,j);
                count++;
                // }
                for(int i = 0; i < N-2 ; i++){
                    for(int j = 0 ; j < M-2 ; j++){
                        if(A[i][j] != B[i][j]){
                            check = false;
                            // break;
                        }
                    }
                }
                if(check) break;
            }
        }
    }

    // bool check = true;
    // for(int i = 0; i < N-2 ; i++){
    //     for(int j = 0 ; j < M-2 ; j++){
    //         if(A[i][j] != B[i][j]){
    //             check = false;
    //             break;
    //         }
    //     }
    // }

    cout << (check ? count : -1);
    
    return 0;
}