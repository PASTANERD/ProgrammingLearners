#include<iostream>
#include<vector>

using namespace std;
int n, m;
int MIN = -1;
char board[20][20], visited1[20][20], visited2[20][20];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
pair<int, int> pre[] = {{0,1},{0,-1},{1,0},{-1,0}};
int x1,y1,x2,y2;

bool out(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m)
        return true;
    return false;
}


void move(int tried, pair<int, int> prev){
    if(tried > 10) return;
    
    if(out(x1, y1) && out(x2, y2))   return;
    else if(out(x1, y1) || out(x2, y2)){
        if(MIN == -1 || MIN > tried) MIN = tried;
        return;
    }
    
    for(int k=0; k<4; k++){
        if(pre[k] == prev) continue;
        
        x1 += dx[k];    y1 += dy[k];
        x2 += dx[k];    y2 += dy[k];
        bool st1 = false, st2 = false;
        if(!out(x1,y1) && board[x1][y1] == '#'){
            st1 = true;
            x1 -= dx[k]; y1 -= dy[k];}
        if(!out(x2,y2) && board[x2][y2] == '#'){
            st2 = true;
            x2 -= dx[k]; y2 -= dy[k];}
        
        if(st1 && st2) continue;
        
        move(tried+1, {dx[k],dy[k]});
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
    
    x1 = coin[0].first;
    y1 = coin[0].second;
    x2 = coin[1].first;
    y2 = coin[1].second;
    
    move(0, {0,0});
    cout << MIN;
}

