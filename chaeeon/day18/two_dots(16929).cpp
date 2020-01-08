/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/16929
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// bool *visit;
int N, M;
bool visit[50][50];
char map[50][50];

int dci[4] = {-1, 0, 0, 1};
int dcj[4] = {0, -1, 1, 0};

bool finder(char v, int si, int sj, int ci, int cj){
    if(visit[ci][cj]) return true;
    
    cout << "current\t-> map[" << ci << "][" << cj << "]" << '\n';
    
    visit[ci][cj] = true;
    for(int i = 0 ; i < 4 ; i++){
        int next_ci = ci + dci[i], next_cj = cj + dcj[i];

        if(next_ci >= N || next_ci >= N || next_cj < 0 || next_cj < 0 || map[next_ci][next_cj] != v) continue;
        else if(!visit[next_ci][next_cj]){
            cout << "next\t-> map[" << next_ci << "][" << next_cj << "]: " << map[next_ci][next_cj] << '\n';
            if(finder(v, si, sj, next_ci, next_cj)) break;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    // vector<int> *adjacent;

    // visit = new bool[N+1];
    // adjacent = new vector<int>[N+1];

    // map = new char*[N];

    for(int i = 0 ; i < N ; i++){
        string line;
        cin >> line;
        // map[i] = new char[M]
        for(int j = 0 ; j < M ; j++){
            map[i][j] = line[j];
        }
    }
    for(int i = 0 ; i < N ; i++) fill_n(visit[i], M, false);

    bool exist = false;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(!visit[i][j]){
                if(finder(map[i][j], i, j, i, j)){
                    exist = true;
                    break;
                }
            }
        }
    }
    
    cout << (exist ? "Yes" : "No");

    return 0;
}
