/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/16948
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N;
bool **visit;

int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};

int bfs(int c_x, int c_y, int d_x, int d_y){
    int distance = 0; // v에서 boundary 까지의 거리
    queue<pair<int, int> > q;
    // int count = 0;

    q.push(make_pair(c_x, c_y));
    visit[c_x][c_y] = true;
    pair<int, int> boundary = q.back();
    bool found = false;
    
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        int cur_x = cur.first, cur_y = cur.second;

        if(cur_x == d_x && cur_y == d_y){
            found = true;
            break;
        }

        for(int i = 0 ; i < 6 ; i++){
            int n_x = cur_x + dx[i], n_y = cur_y + dy[i];
            // cout << "(n_x, n_y) = (" << n_x << ", " << n_y << ")\n";
            if(n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) continue;
            if(!visit[n_x][n_y]){
                q.push(make_pair(n_x, n_y));
                visit[n_x][n_y] = true;
            }
        }

        if(cur_x == boundary.first && cur_y == boundary.second){
            boundary = q.back();
            distance++;
        }
    }
    if(!found) distance = -1;
    return distance;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    // N = 7;

    int c_x, c_y, d_x, d_y;
    cin >> c_x >> c_y >> d_x >> d_y;
    // c_x = 6; c_y = 6; d_x = 0; d_y = 1;
    // cout << c_x << c_y << d_x << d_y;

    visit = new bool*[N];
    for(int i = 0 ; i < N ; i++) {
        visit[i] = new bool[N];
        fill_n(visit[i], N, false);
    }

    cout << bfs(c_x, c_y, d_x, d_y);

    return 0;
}