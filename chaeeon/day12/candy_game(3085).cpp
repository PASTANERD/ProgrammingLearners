/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/3085
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/


#include <iostream>
#include <string>

using namespace std;

int count_candy(string target){
    int best = 0;
    char temp;
    
    temp = target[0];
    int count = 1;

    for(int i = 1 ; i < target.size() ; i++){
        if(temp == target[i]) count++;
        else {
            temp = target[i];
            count = 1;
        }
        if(best < count) best = count;
    }
    return best;
}

string columnize(string* board, int index){
    string column = "";
    for(int i = 0 ; i < board[index].size() ; i++)
        column.push_back(board[i][index]);

    return column;
}

int best_case(string *board){
    int best = 0;
    int N = board[0].size();
    for(int i = 0 ; i < N ; i++) 
        best = max(best, max(count_candy(board[i]), count_candy(columnize(board, i))));    

    return best;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string board[N];
    for(int i = 0 ; i < N ; i++) {
        cin >> board[i];
    }

    int best = 0;
    char temp;
    
    for(int i = 0; i < N-1 ; i++){
        for(int j = 0 ; j < N-1 ; j++){
            // Horizontal
            temp = board[i][j];
            board[i][j] = board[i][j+1];
            board[i][j+1] = temp;

            best = max(best, best_case(board));

            board[i][j+1] = board[i][j];
            board[i][j] = temp;

            // Vertical
            temp = board[j][i];
            board[j][i] = board[j+1][i];
            board[j+1][i] = temp;

            best = max(best, best_case(board));

            // recover
            board[j+1][i] = board[j][i];
            board[j][i] = temp;   
        }
    }

    // Horizontal
    temp = board[N-1][N-1];
    board[N-1][N-1] = board[N-1][N-2];
    board[N-1][N-2] = temp;

    best = max(best, best_case(board));

    board[N-1][N-2] = board[N-1][N-1];
    board[N-1][N-1] = temp;

    // Vertical
    temp = board[N-1][N-1];
    board[N-2][N-1] = board[N-2][N-1];
    board[N-2][N-1] = temp;

    best = max(best, best_case(board));

    cout << best;

    return 0;
}