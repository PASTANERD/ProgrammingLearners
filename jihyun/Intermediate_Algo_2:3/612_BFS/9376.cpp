
//9376

#include <iostream>
#include <deque>
#include <vector>
#include <tuple>

using namespace std;

int d[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};

vector<vector<int>> BFS(vector<string> &pr, int x, int y){
    int h = pr.size();
    int w = pr[0].size();
    vector<vector<int>> v(h,vector<int>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            v[i][j] = -1;
        }
    }
    deque<pair<int,int>> q;
    q.push_back({x,y});
    v[x][y] = 0;
    
    while(!q.empty()){
        tie(x,y) = q.front(); q.pop_front();
        for(int k=0; k<4; k++){
            int nx = x+d[k][0];
            int ny = y+d[k][1];
            if(nx<0 || nx>=h || ny<0 || ny>=w)  continue;
            if(v[nx][ny] != -1 || pr[nx][ny]=='*') continue;
            if(pr[nx][ny]=='#'){
                v[nx][ny] = v[x][y] + 1;
                q.push_back({nx,ny});
            }else{
                v[nx][ny] = v[x][y];
                q.push_front({nx,ny});
            }
        }
    }
    
    return v;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int h,w;
        cin >> h >> w;
        vector<string> pr(h+2);
        for(int i=1; i<=h; i++){
            cin >> pr[i];
            pr[i] = '.' + pr[i] + '.';
        }
        h += 2;
        w += 2;
        for(int j=0; j<w; j++){
            pr[0] += '.';
            pr[h-1] += '.';
        }
        
        vector<vector<int>> v0 = BFS(pr,0,0);
        
        vector<pair<int,int>> prisoner;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(pr[i][j] == '$'){
                    prisoner.push_back({i,j});
                }
            }
        }
        
        vector<vector<int>> v1 = BFS(pr,prisoner[0].first,prisoner[0].second);
        vector<vector<int>> v2 = BFS(pr,prisoner[1].first,prisoner[1].second);
        
        int ans = h*w;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(pr[i][j] == '*') continue;
                int cur = v0[i][j] + v1[i][j] + v2[i][j];
                if(pr[i][j]=='#')
                    cur -= 2;
                ans = min(ans,cur);
            }
        }
        cout << ans << '\n';
    }
}
