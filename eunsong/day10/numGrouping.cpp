#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> num(n);
    for(int i=0; i<n; i++)
        cin >> num[i];
    
    vector<int> plus, minus;
    int zero=0, one=0;
    for(int i=0; i<n; i++){
        if(num[i] == 1)
            one += 1;
        else if(num[i] > 0)
            plus.push_back(num[i]);
        else if(num[i] < 0)
            minus.push_back(num[i]);
        else
            zero += 1;
    }

    sort(plus.begin(), plus.end());
    reverse(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());

    int ans=one;
    if(plus.size()%2 == 1)
        plus.push_back(1);
    if(minus.size()%2 == 1)
        minus.push_back(zero>0 ? 0 : 1);

    for(int i=0; i<plus.size(); i += 2)
        ans += plus[i]*plus[i+1];
    for(int i=0; i<minus.size(); i+=2)
        ans += minus[i]*minus[i+1];

    cout << ans << "\n";

    return 0;
}