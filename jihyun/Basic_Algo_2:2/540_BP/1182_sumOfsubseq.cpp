//1182

#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, s;
    cin >> n >> s;
    
    int* num = new int[n];
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    
    int ans = 0;
    for(int i=1; i<(1<<n); i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            if(i&(1<<j))
                sum += num[j];
        }
        if(sum == s)
            ans++;
    }
    
    cout << ans;
}
