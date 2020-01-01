#include <iostream>
#include <algorithm>

using namespace std;

bool broken[10] = {false};
bool check(int c){
    if(c == 0){
        if(broken[0])
            return false;
    }
    while(c>0){
        if(broken[c%10])
            return false;
        c /= 10;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int temp;
        cin >> temp;
        broken[temp] = true;
    }


    int ans = abs(100 - n);
    if(n == 100){
        ans = 0;
        cout << ans << "\n";
        return 0;
    }

    if(t == 10){
        cout << ans << "\n";
        return 0;
    }

    for(int i=0; i<1000000; i++){
        string s = to_string(i);
        if(check(i)){
            int len = s.size();
            len += abs(n-i);
            if(ans > len) {
                ans = len;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}