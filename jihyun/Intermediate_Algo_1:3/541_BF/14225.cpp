
//14225
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> s(n);
    for(int i=0; i<n; i++)
        cin >> s[i];
    
    sort(s.begin(), s.end());
    
    int cur = 0;
    for(int i=0; i<(1<<n); i++){
        int sum=0;
        for(int j=0; j<n; j++){
            if(i&(1<<j))
                sum+=s[j];
        }
        if(sum>cur)    break;
        if(sum==cur)   cur++;
    }
    cout << cur << '\n';
}
