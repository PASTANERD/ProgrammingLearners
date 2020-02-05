
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

typedef struct _ball{
    int bx1, by1, bx2, by2;
    _ball(int _x1, int _y1, int _x2, int _y2) : bx1(_x1), by1(_y1), bx2(_x2), by2(_y2) {}
}ball;

int n, m;
char board[20][20];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int dist[20][20][20][20];

bool out(int x, int y){
    if(x<0 || x>n-1 || y<0 || y>m-1)
        return true;
    return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    vector<pair<int, int>> coin;
    memset(dist, -1, sizeof(dist));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] == 'o')
                coin.push_back({i,j});
        }
    }
    
    int bx1 = coin[0].first;
    int by1 = coin[0].second;
    int bx2 = coin[1].first;
    int by2 = coin[1].second;
    
    queue<ball> q;
    dist[bx1][by1][bx2][by2] = 0;
    q.push(ball(bx1, by1, bx2, by2));
    
    while (!q.empty()) {
        ball b = q.front();
        q.pop();
        
        int x1, y1, x2, y2;
        x1 = b.bx1; y1 = b.by1; x2 = b.bx2; y2 = b.by2;
        
        if (dist[x1][y1][x2][y2] == 10) {
            break;
        }
        
        for (int k = 0; k < 4; k++) {
            int tx1, ty1, tx2, ty2;
            tx1 = x1 + dx[k];
            ty1 = y1 + dy[k];
            tx2 = x2 + dx[k];
            ty2 = y2 + dy[k];
            
            if (out(tx1, ty1) && out(tx2, ty2)) continue;
            
            if (out(tx1, ty1) ^ out(tx2, ty2)) {
                cout << dist[x1][y1][x2][y2] + 1 << '\n';
                return 0;
            }
            
            if (!out(tx1, ty1)) {
                if (board[tx1][ty1] == '#') {
                    tx1 -= dx[k];
                    ty1 -= dy[k];
                }
            }
            if (!out(tx2, ty2)) {
                if (board[tx2][ty2] == '#') {
                    tx2 -= dx[k];
                    ty2 -= dy[k];
                }
            }
            
            if (dist[tx1][ty1][tx2][ty2] == -1) {
                dist[tx1][ty1][tx2][ty2] = dist[x1][y1][x2][y2] + 1;
                q.push(ball(tx1, ty1, tx2, ty2));
            }
        }
    }
    
    cout << -1;
    return 0;
}

