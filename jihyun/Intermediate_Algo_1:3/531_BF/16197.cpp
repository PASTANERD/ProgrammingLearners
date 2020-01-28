#include<iostream>
#include<vector>

using namespace std;
int n, m;
int MIN = -1;
char board[21][21];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool out(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m)
        return true;
    return false;
}

void move(int x1, int y1, int x2, int y2, int tried){
    
    if(tried > 10) return;
    if(out(x1, y1) && out(x2, y2))  return;
    if(out(x1, y1) || out(x2, y2)){
        if(MIN == -1 || MIN > tried)
            MIN = tried;
        return;
    }
    if(x1 == x2 && y1 == y2) return;
    
    for(int k=0; k<4; k++){
        
        int tx1 = x1+dx[k];
        int ty1 = y1+dy[k];
        int tx2 = x2+dx[k];
        int ty2 = y2+dy[k];
        
        bool st1 = false, st2 = false;
        if(!out(tx1,ty1) && board[tx1][ty1] == '#'){
            st1 = true;
            tx1-=dx[k]; ty1-=dy[k];
        }
        if(!out(tx2,ty2) && board[tx2][ty2] == '#'){
            st2 = true;
            tx2-=dx[k]; ty2-=dy[k];
        }
        
        if(st1 && st2) continue;
        
        move(tx1, ty1, tx2, ty2, tried+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    vector<pair<int, int>> coin;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] == 'o')
                coin.push_back({i,j});
        }
    }
    
    move(coin[0].first, coin[0].second, coin[1].first, coin[1].second, 0);
    cout << MIN;
}




