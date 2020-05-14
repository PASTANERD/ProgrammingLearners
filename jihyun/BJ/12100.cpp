//12100 - 2048(easy)
#include <iostream>
#include <algorithm>

using namespace std;
int MAX = 0;
int N;

void move(int board[][20], int cnt){
    if(cnt > 5) return;
    
    for(int k=0; k<4; k++){
        //move UP
        int new_b[20][20] = {0,};
        int row = 0, col = 0;               //new board를 위한 행,열
        
        for(int j=0; j<N; j++){
            bool merged[20] = {false,};     //이미 합쳐진 적이 있는지 체크
            row = 0;
            for(int i=0; i<N; i++){
                if(board[i][j]==0) continue;
                //가능한 가장 위에 숫자 넣기
                new_b[row][col] = board[i][j];
                //그 위에 칸 숫자랑 일치할 경우 합치기
                if(!merged[row-1] && row-1 >= 0 && new_b[row-1][col]==new_b[row][col]){
                    new_b[row-1][col] *= 2;
                    new_b[row][col] = 0;
                    merged[row-1] = true;
                    MAX = max(MAX,new_b[row-1][col]);
                    row--;
                }
                row++;
            }
            col++;
        }
        move(new_b,cnt+1);
        
        //turn right (90도)
        int turn_b[20][20] = {{0,}};
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                turn_b[j][N-1-i] = board[i][j];
            }
        }
        for(int i=0; i<N; i++)
            copy(turn_b[i], turn_b[i]+N, board[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int board[20][20];
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int temp;
            cin >> temp;
            board[i][j] = temp;
            if(MAX < temp) MAX = temp;
        }
    }
    move(board,1);
    cout << MAX;
}

