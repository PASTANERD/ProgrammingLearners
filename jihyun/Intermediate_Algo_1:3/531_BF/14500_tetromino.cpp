
#include <iostream>
#include <vector>
using namespace std;
int row, col;
int MAX = 0;
int nums[500][500];
bool visited[500][500];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
#define MAX(a,b) a > b ? a : b;

void go(int x, int y, int sum, int cnt){
    if(cnt == 4){
        MAX = MAX(sum,MAX);
        return;
    }
    
    if(x<0 || x>=row || y<0 || y>=col) return;
    if(visited[x][y]) return;
    visited[x][y] = true;
    for(int k=0; k<4; k++)
        go(x+dx[k], y+dy[k], sum+nums[x][y], cnt+1);
    visited[x][y] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> row >> col;
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            cin >> nums[i][j];
    }
    
    //모든 경우 다 해보깃..
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            go(i,j,0,0);
            if(j+2<col){
                int temp = nums[i][j] + nums[i][j+1] + nums[i][j+2];
                if(i-1 >= 0){
                    int temp2 = temp + nums[i-1][j+1];
                    MAX = MAX(MAX,temp2);
                }
                if(i+1 < row){
                    int temp2 = temp + nums[i+1][j+1];
                    MAX = MAX(MAX,temp2);
                }
            }
            if(i+2<row){
                int temp = nums[i][j] + nums[i+1][j] + nums[i+2][j];
                if(j-1 >= 0){
                    int temp2 = temp + nums[i+1][j-1];
                    MAX = MAX(MAX,temp2);
                }
                if(j+1 < col){
                    int temp2 = temp + nums[i+1][j+1];
                    MAX = MAX(MAX,temp2);
                }
            }
        }
    }
    
    
    
    
    cout << MAX;
}

