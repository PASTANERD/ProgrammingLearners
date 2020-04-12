#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int N, M;    //세로, 가로
    int r, c, d;    //현재 로봇청소기가 있는 좌표(r,c)와 방향

    cin >> N >> M;
    cin >> r >> c >> d;

    int area[N][M];
    int cnt = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> area[i][j];
        }
    }
    
    queue<tuple<int,int,int>> q;
    q.push({r,c,d});


    while(!q.empty()){
        int x,y,z;
        tie(x,y,z) = q.front(); q.pop();
        
        //현재 위치 청소
        area[x][y] = 2;
        cnt++;
        
        int tz = z;
        while(1){
            //현재 방향 기준, 왼쪽 방향부터 탐색
            int lz = (tz-1)<0 ? 3 : tz-1;
            int lx = x+dx[lz];
            int ly = y+dy[lz];

            //a 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
            if(area[lx][ly]==0){
                q.push({lx,ly,lz});
                break;
            }

            //b왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
            tz = lz;
            //c 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
            if(tz==z){
                int back = (tz-2)>=0 ? tz-2 : (tz==1 ? 3 : 2);
                x += dx[back];
                y += dy[back];

                //d 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
                if(area[x][y]==1){
                    cout << cnt << '\n';
                    exit(0);
                }
            }

        }
    }

    cout << cnt << '\n';
}

