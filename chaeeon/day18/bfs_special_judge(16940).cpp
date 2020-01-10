/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/14889
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool *visit;

void bfs(int v, vector<int> *e, vector<int> answer){
    queue<int> q;
    int current = 0;
    bool correct = false;
    
    index = 1;
    q.push(v);
    visit[v] = true;
    while(!q.empty()){
        current = q.front();
        q.pop();
        for(vector<int>::iterator next = e[current].begin() ; next != e[current].end() ; next++){
            if(!visit[*next]) {
                q.push(*next);
                visit[*next] = true;
            }
        }
        for(queue<int>::iterator check = queue.begin() ; check != queue.end() ; check++){
            if(*check == answer[index]){
                index++;
                correct = true;
            }
        }
        if(!correct) break;
        else correct = false;
    }
    if(correct) cout << 1;
    else 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> *adjacent;

    visit = new bool[N+1];
    adjacent = new vector<int>[N+1];

    for(int i = 0 ; i < N-1 ; i++){
        int x, y;
        cin >> x >> y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }
    
    vector<int> answer;
    for(int i = 1; i <= N ; i++){
        int temp;
        cin >> temp;
        answer.push_back(temp);
    }
    // bfs
    fill_n(visit, N+1, false);
    bfs(answer.front(), adjacent, answer);

    return 0;
}
