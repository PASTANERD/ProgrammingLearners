/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/14889
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int,int> > edges;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> adjacent[N];
    bool matrix[N][N];

    for(int i = 0 ; i < N ; i++)fill_n(matrix[i], N, false);

    int x, y;
    for(int i = 0 ; i < M ; i++){
        cin >> x >> y;
        edges.push_back(make_pair(x, y));
        edges.push_back(make_pair(y, x));
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
        matrix[x][y] = matrix[y][x] = true;
    }

    bool check = false;

    for(auto v1 = edges.begin() ; v1 != edges.end() ; v1++){
        int A = v1->first;
        int B = v1->second;

        for(auto v2 = edges.begin() ; v2 != edges.end() ; v2++){
            int C = v2->first;
            int D = v2->second;
            if(C != A && C != B && D != A && D != B && matrix[B][C]){
                for(auto E = adjacent[D].begin() ; E != adjacent[D].end() ; E++){
                    if(*E != A && *E != B && *E != C) check = true;
                }
            }
        }
    }

    cout << (check ? 1 : 0);

    return 0;
}
