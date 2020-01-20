
/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/14225
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define TOTAL 20*100000+1
using namespace std;

int N;
int maximus = 0;

bool *visit;
void dfs(int v, int k, int *seq){
    if(k == N){
        visit[v] = true;
        return;
    }
    dfs(v+seq[k], k+1, seq);
    dfs(v, k+1, seq);   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    int sequence[N];

    for(int i = 0 ; i < N ; i++) {
        cin >> sequence[i];
        maximus += sequence[i];
    }
    visit = new bool[maximus+1];
    fill_n(visit, maximus+1, false);

    dfs(0, 0, sequence);

    for(int i = 1 ; i <= maximus+1 ; i++){
        if(!visit[i]){
            cout << i;
            break;
        }
    }
    return 0;
}