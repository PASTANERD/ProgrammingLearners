/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/14889
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int S[N][N];

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ;j++){
            cin >> S[i][j];
        }
    }

    int answer = 20*100;

    vector<int> link;
    vector<int> start;
    int tlink, tstart;
    for(int i = 1 ; i < (1<<N) ; i++){
        for(int j = 0; j < N ; j++){
            if(i & (1 << j)) link.push_back(j);
            else start.push_back(j);
        }

        tlink = 0, tstart = 0;
        if(link.size() == N/2){
            for(int m = 0; m < N/2 ; m++){
                for(int n = 0 ; n < N/2 ; n++){
                    tlink += S[link[m]][link[n]];
                    tstart += S[start[m]][start[n]];
                }
            }
            answer = min(answer, abs(tlink - tstart));
        }
        link.clear();
        start.clear();
        
    }

    cout << answer;

    return 0;
}
