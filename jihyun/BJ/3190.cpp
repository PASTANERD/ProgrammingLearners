//3190
#include<iostream>
#include<vector>
#include<queue>
#include<list>

using namespace std;

int dx[4] = {0,1,0,-1}; //오른쪽으로 회전하는 순서
int dy[4] = {1,0,-1,0};

int main(void) {
    
    int N, K, L;
    cin >> N >> K;
    
    vector<pair<int,int>> apples;   //사과 위치
    for(int i=0; i<K; i++){
        int a, b;
        cin >> a >> b;
        apples.push_back({a,b});
    }
    
    cin >> L;
    queue<pair<int,char>> move;     //뱀 이동경로
    for(int i=0; i<L; i++){
        int a; char b;
        cin >> a >> b;
        move.push({a,b});
    }
    
    int time = 0, cur_d = 0;
    list<pair<int,int>> snake;
    snake.push_back({1,1});
    pair<int,int> head = {1,1};
    
    while(1){
        time++;
        //다음 칸으로 머리 이동
        head = {head.first + dx[cur_d], head.second + dy[cur_d]};
        
        //벽 또는 자기 자신과 부딪히면 게임 종료
        if(head.first<=0 || head.second<=0 || head.first>N || head.second>N)
            break;
        if(find(snake.begin(), snake.end(), head) != snake.end())
            break;
            
        snake.push_back(head);
        
        //사과 체크
        auto k = find(apples.begin(), apples.end(), head);
        if(k == apples.end())
            snake.pop_front();
        else
            apples.erase(k);

        //방향 변환 해야 할 때
        if(move.front().first == time){
            if(move.front().second == 'L')
                cur_d = (cur_d == 0) ? 3 : cur_d-1;
            else
                cur_d = (cur_d == 3) ? 0 : cur_d+1;
            move.pop();
        }
    }
    
    cout << time << '\n';
}

