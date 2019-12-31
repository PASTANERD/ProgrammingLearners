/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/3085
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

    for(int i = 0 ; i < board[index].size() ; i++){
        column.push_back(board[i][index]);
    }

    return column;
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

    int best;
    int count_row;
    int count_col;
    string target_column;
    
    char temp;
    
    for(int i = 0; i < N-1 ; i++){
        for(int j = 0 ; j < N-1 ; j++){
            // Horizontal
            temp = board[i][j];
            board[i][j] = board[i][j+1];
            board[i][j+1] = temp;

            //row count
            count_row = count_candy(board[i]);
            //column count
            target_column = columnize(board, j);
            count_col = count_candy(target_column);
            best = max(best,max(count_row, count_col));

            //row+1 count
            count_row = count_candy(board[i+1]);
            
            //column+1 count
            target_column = columnize(board, j+1);
            count_col = count_candy(target_column);

            best = max(best,max(count_row, count_col));

            // recover
            board[i][j+1] = board[i][j];
            board[i][j] = temp;

            // Vertical
            temp = board[j][i];
            board[j][i] = board[j+1][i];
            board[j+1][i] = temp;

            //row count
            count_row = count_candy(board[j]);

            //column count
            target_column = columnize(board, i);
            count_col = count_candy(target_column);
            best = max(best,max(count_row, count_col));

            //row+1 count
            count_row = count_candy(board[j+1]);
            
            //column+1 count
            target_column = columnize(board, i+1);
            count_col = count_candy(target_column);

            best = max(best,max(count_row, count_col));

            // recover
            board[j+1][i] = board[j][i];
            board[j][i] = temp;   
        }
    }

    cout << best;

    return 0;
}