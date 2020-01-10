#include <iostream>

using namespace std;

int *a;
int *d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    a = new int[n];
    d = new int[n];
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    int ans = d[0] = a[0];
    
    for(int i=1; i<n; i++){
        d[i] = (d[i-1]+a[i] > a[i])? d[i-1]+a[i] : a[i];
        if(ans < d[i])
            ans = d[i];
    }

    cout << ans << '\n';
}
