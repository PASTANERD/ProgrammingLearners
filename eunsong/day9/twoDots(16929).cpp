#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool check[50][50] = {false};
int arr[50][50] = {0};
int dist[50][50] = {0};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n,m;

bool cycle(int x, int y, int cnt, char color){
    //거리의 차이가 4 이상이면 return true;
    if(check[x][y]) return cnt-dist[x][y]>=4;
        //if(cnt - dist[x][y]>= 4) 
        //    return true;
    check[x][y] = true; 
    dist[x][y] = cnt;
    //cout << x << " " << y << endl;
    for(int i=0; i<4; i++){
        int nx = x+dx[i], ny = y+dy[i];
        if((0<=nx && nx<n) && (0<=ny && ny<m))
            if(arr[nx][ny] == color){
                //cout <<"nx:"<< nx << " " <<"ny:"<< ny << endl;
                if(cycle(nx,ny,cnt+1,color))
                    return true;
            }
    }   
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        for(int j=0; j<temp.length(); j++)
            arr[i][j] = temp[j];
    }

    bool ans = false;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!check[i][j]){
                if(cycle(i,j,0,arr[i][j])){
                    cout << "Yes" << "\n";
                    return 0;
                }
            }
        
    cout << "No" << endl;

    return 0;
}