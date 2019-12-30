/*
input
첫째 줄에 민규가 구매하려고 하는 카드의 개수 N이 주어진다. (1 ≤ N ≤ 1,000)
둘째 줄에는 Pi가 P1부터 PN까지 순서대로 주어진다. (1 ≤ Pi ≤ 10,000)

output
첫째 줄에 민규가 카드 N개를 갖기 위해 지불해야 하는 금액의 최솟값을 출력한다.
*/

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    int *d = new int[n+1];
    int *p = new int[n+1];
    
    fill_n(d,n+1,-1);
    d[0] = 0;
    
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            int cur = d[i];
            int temp = d[i-j] + p[j];
            if(cur == -1 || cur > temp)
                d[i] = temp;
        }
    }
    cout << d[n];
}
