//input : 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
//둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

#include <iostream>

using namespace std;

int *a;
int *d;
int *v;
int last = 0;

void go(int p){
    if(p == 0){
        cout << a[p] << ' ';
        return;
    }
    if(p == last){
        go(v[p]);
        cout << a[p];    
    }
    else{
        go(v[p]);
        cout << a[p] << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    a = new int[n];
    d = new int[n];
    v = new int[n];
    int ans = 0;
    
    for(int i=0; i<n; i++){
        v[i] = 0;
        cin >> a[i];
    }
    
    for(int i=0; i<n; i++){
        d[i] = 1;
        for(int j=0; j<i; j++){
            if(a[j] < a[i] && d[i] < d[j]+1){
                d[i] = d[j]+1;
                v[i] = j;
            }
        }
        if(ans <= d[i]){
            ans = d[i];
            last = i;
        }
    }

    cout << ans << '\n';
    go(last);
}
