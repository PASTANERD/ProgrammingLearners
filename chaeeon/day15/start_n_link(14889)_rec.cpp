/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/14889
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
using namespace std;

int **S;
int *start;
int *link;

int go(int capacity, int index, int n){
    int answer = 20*100;
    if(capacity == n){
        // check difference
        int k = 0;
        bool islink = true;
        for(int i = 0 ; i < n*2 ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == start[j]) islink = false;
            }
            if(islink) {
                link[k] = i;
                k++;
            }
            islink = true;
        }
        int t_start = 0;
        int t_link = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                t_start += S[start[i]][start[j]];
                t_link += S[link[i]][link[j]];
            }
        }

        return abs(t_start - t_link);
    }
    else{
        if(index >= n*2) return 20*100;
        
        start[capacity] = index;
        answer = min(answer ,go(capacity+1, index+1, n));
        start[capacity] = -1;
        answer = min(answer, go(capacity, index+1, n));
    }
    
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    S = new int*[N];
    start = new int[N/2];
    link = new int[N/2];

    for(int i = 0 ; i < N ; i++){
        S[i] = new int[N];
        for(int j = 0 ; j < N ;j++){
            cin >> S[i][j];
        }
    }
    
    cout << go(0, 0, N/2);
    
    return 0;
}
