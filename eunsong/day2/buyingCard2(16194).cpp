#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int *P = new int[N+1];
    for(int i=1; i<=N; i++)
        cin >> P[i];
    
    int *D = new int[N+1];

    /******초깃값 설정*********
     * N<=1000
     * 카드팩 가격 <=10000
     * 정답은 1000*10000 넘지 않음
    *************************/
    for(int i=1; i<=N; i++)
        D[i] = 1000*10000;
    D[0] = 0;

    for(int i=1; i<=N; i++)
        for(int j=1; j<=i; j++)
            D[i] = min(D[i], D[i-j]+P[j]);

    cout <<  D[N] << "\n";
    return 0;
}