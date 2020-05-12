// 13460 구슬 탈출 2
// NxM 보드
// 빨간 구슬, 파란 구슬이 보드 안에 있고, 그 중 빨간 구슬만! 구멍을 통해 빼내야 함
// 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램

#include <iostream>
#include <queue>

using namespace std;

struct info{
    int rx, ry, bx, by, count;
};

info start;
char board[10][11];

int bfs(){
    const int dx[] = {-1,1,0,0};
    const int dy[] = {0,0,-1,1};
    
    int visited[10][10][10][10] = {0,};
    queue<info> q;
    q.push(start);
    visited[start.rx][start.ry][start.bx][start.by] = 1;
    
    int cnt = -1;
    while(!q.empty()){
        info cur = q.front();
        q.pop();
        
        if(cur.count > 10) break;
        
        if(board[cur.rx][cur.ry] == 'O' && board[cur.bx][cur.by] != 'O'){
            cnt = cur.count;
            break;
        }
        
        /*******여기에 왜 break를 넣으면 안되나요1?!??!*******/
        //if(cur.count > 9) break;
        /*********************************************************/
        
        for(int dir=0; dir<4; dir++){
            info next;
            next.rx = cur.rx;
            next.ry = cur.ry;
            next.bx = cur.bx;
            next.by = cur.by;
            
            //move red
            while(1){
                if(board[next.rx][next.ry] != '#' && board[next.rx][next.ry] != 'O'){
                    next.rx += dx[dir];
                    next.ry += dy[dir];
                }
                else{
                    if(board[next.rx][next.ry] == '#'){
                       next.rx -= dx[dir]; next.ry -= dy[dir];
                   }
                    break;
                }
            }
            
            
            //move blue
            while(1){
                if(board[next.bx][next.by] != '#' && board[next.bx][next.by] != 'O'){
                    next.bx += dx[dir];
                    next.by += dy[dir];
                }
                else{
                    if(board[next.bx][next.by] == '#'){
                       next.bx -= dx[dir]; next.by -= dy[dir];
                   }
                    break;
                }
            }

            //blue가 구멍 빠졌을 때
            if(board[next.bx][next.by] == 'O')
                continue;
            
            //if red and blue are same
            if(next.rx == next.bx && next.ry == next.by){
                int red_dis = abs(next.rx-cur.rx) + abs(next.ry-cur.ry);
                int blue_dis = abs(next.bx-cur.bx) + abs(next.by-cur.by);
                if(red_dis > blue_dis){
                    next.rx -= dx[dir]; next.ry -= dy[dir];
                }else{
                    next.bx -= dx[dir]; next.by -= dy[dir];
                }
            }
            
            if(visited[next.rx][next.ry][next.bx][next.by] == 0){
                visited[next.rx][next.ry][next.bx][next.by] = 1;
                next.count = cur.count + 1;
                q.push(next);
            }
        }
    }
    
    return cnt;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;   // (3 ≤ N, M ≤ 10)
    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> board[i];
        
        for(int j=0; j<M; j++){
            if(board[i][j] == 'R'){
                start.rx = i; start.ry = j;}
            else if(board[i][j] == 'B'){
                start.bx = i; start.by = j;}
        }
    }
    start.count = 0;

    int answer = bfs();
    cout << answer << endl;
    
}

