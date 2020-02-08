
//2110
#include <iostream>
#include <algorithm>

using namespace std;
int C, N;

bool possible(int a[], int dif){
    int cnt = 1;
    int last = a[0];
    for(int i=0; i<N; i++){
        if(a[i] - last >= dif){
            cnt++;
            last = a[i];
        }
    }
    return cnt >= C;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> C;
    
    int home[N];
    
    for(int i=0; i<N; i++)
        cin >> home[i];
    
    sort(home, home+N);
    
    int ans = 0;
    int left = 0;
    int right = home[N-1]-home[0];
    
    while(left <= right){
        int mid = (left+right) / 2;
        if(possible(home, mid)){
            left = mid + 1;
            ans = mid;
        }
        else
            right = mid - 1;
    }
    
    cout << ans;
}
