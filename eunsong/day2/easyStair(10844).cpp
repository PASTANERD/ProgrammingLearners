#include <iostream>

using namespace std;

#define divisor 1000000000

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    long **D = new long*[N+1];
    for(int i=0; i<N+1; i++)
        D[i] = new long[9];

    for(int i=1; i<=9; i++)
        D[1][i] = 1;
    for(int i=2; i<=N; i++){
        for(int j=0; j<=9; j++){
            D[i][j] = 0;
            if(j>=1)    D[i][j] += D[i-1][j-1];
            if(j<9)     D[i][j] += D[i-1][j+1];
            D[i][j] = D[i][j] % divisor;
        }
    }
    
    long long answer = 0;
    for(int i=0; i<=9; i++)
        answer += D[N][i];
    answer %= divisor;

    cout << answer << "\n";

    return 0;
}