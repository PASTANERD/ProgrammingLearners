#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;

    int ans1 = 0, ans2 = 0, ans3 = 0;
    if(k%2 == 1){
        n -= (k/2 + 1);
        m -= k/2;
        ans1 = n/m;
    }
    else{
        n -= k/2;
        m -= k/2;
        ans2 = n/m;
    }

    cout << ans << "\n";

    return 0;
}