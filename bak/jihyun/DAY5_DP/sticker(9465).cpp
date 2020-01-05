#include <iostream>
#include <algorithm>

using namespace std;

int mod = 10007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //d[i][j] : 2xi에서의 최대 점수, 마지막에 뜯는 스티커 -> j (0:뜯x, 1:위쪽, 2:아래쪽)
    int d[100001][3] = {{0,},};
    
    int size;
    cin >> size;
    
    while(size--){
        int n;
        cin >> n;
        
        //score[i][j] : i=0 위쪽 i=1 아래쪽 / j번째 스티커 점수
        int **score = new int*[n+1];
        for(int i=0; i<=n; i++){
            score[i] = new int[2];
        }
        
        for(int i=0; i<2; i++)
            for(int j=1; j<=n; j++)
                cin >> score[j][i];
        
        d[1][0] = 0;
        d[1][1] = score[1][0];
        d[1][2] = score[1][1];
        
        for(int i=2; i<=n; i++){
            d[i][0] = max({d[i-1][0],d[i-1][1], d[i-1][2]});
            d[i][1] = max(d[i-1][0],d[i-1][2]) + score[i][0];
            d[i][2] = max(d[i-1][0],d[i-1][1]) + score[i][1];
        }
        
        cout << max({d[n][0],d[n][1],d[n][2]}) << '\n';
    }
}
