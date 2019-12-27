#include <iostream>

using namespace std;

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int N;
    cin >> N;

    long D[N+1][2];
    D[1][0] = 0;
    D[1][1] = 1;

    for(int i=2; i<=N; i++){
        D[i][0] = D[i-1][0] + D[i-1][1];
        D[i][1] = D[i-1][0];
    }

    cout << D[N][0] + D[N][1] << "\n";

    return 0;
}