#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    vector<int> sign;
    vector<int> num;
    int cur = 0;
    sign.push_back(1);
    for(int i=0; i<s.size(); i++){
        if(s[i] == '-' || s[i] == '+'){
            if(s[i] == '-')
                sign.push_back(-1);
            else 
                sign.push_back(1);
            num.push_back(cur);
            cur=0;
        }else{
            cur = 10*cur + (s[i]-'0');
        }
    }
    num.push_back(cur);

    bool minus = false;
    int ans = 0;
    for(int i=0; i<num.size(); i++){
        if(sign[i] == -1)
            minus = true;
        if(minus){
            ans -= num[i];
        }
        else{
            ans += num[i];
        }
    }
    cout << ans << "\n";

    return 0;
}