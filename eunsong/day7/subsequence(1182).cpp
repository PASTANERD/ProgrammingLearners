#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, s;
    cin >> n >> s;

    int *num = new int[n];
    for(int i=0; i<n; i++)
        cin >> num[i];
    
    int ans=0;
    for(int i=1; i<(1<<n); i++){
        int sum=0;
        for(int k=0; k<n; k++){
            if(i&(1<<k))
                sum += num[k];
        }
        if(sum == s)
            ans += 1;
    }
    
    cout << ans << "\n";

    return 0;
}