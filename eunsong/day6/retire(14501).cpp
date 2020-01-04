#include <iostream>
#include <algorithm>

using namespace std;
int ans=0;
int n;
int *T, *P;
void schedule(int day, int sum){
    if(day == n+1){
        ans = (sum > ans) ? sum : ans;
        return;
    }
    if(day>n+1) return;
    schedule(day+T[day], sum+P[day]);
    schedule(day+1, sum);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    T = new int[n+1];
    P = new int[n+1];

    for(int i=1; i<=n; i++)
        cin >> T[i] >> P[i];
    
    schedule(1, 0);

    cout << ans << "\n";
    return 0;
}
