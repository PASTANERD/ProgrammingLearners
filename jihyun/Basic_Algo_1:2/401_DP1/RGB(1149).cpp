/*
 input :  첫째 줄에 집의 수 N, 둘째 줄부터 N개의 줄에 각 집을 빨강으로, 초록으로, 파랑으로 칠하는 비용
 output : 모든 집을 칠하는 비용의 최솟값
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int num;
    cin >> num;
    
    int d[1001][3] = {{0,},};
    
    //cost[i][j] : j=0(red) j=1(green) j=2(blue) i번째 집 j로 색칠하는 비용
    int **cost = new int*[num+1];
    for(int i=0; i<=num; i++){
        cost[i] = new int[3];
    }
    
    for(int i=1; i<=num; i++){
        for(int j=0; j<3; j++)
            cin >> cost[i][j];
    }
    
    d[1][0] = cost[1][0];
    d[1][1] = cost[1][1];
    d[1][2] = cost[1][2];
    
    int ans = min({d[1][0],d[1][1],d[1][2]});
    
    for(int i=2; i<=num; i++){
        d[i][0] = min(d[i-1][1],d[i-1][2]) + cost[i][0];
        d[i][1] = min(d[i-1][0],d[i-1][2]) + cost[i][1];
        d[i][2] = min(d[i-1][0],d[i-1][1]) + cost[i][2];
        ans = min({d[i][0],d[i][1],d[i][2]});
    }
    
    cout << ans;
}
