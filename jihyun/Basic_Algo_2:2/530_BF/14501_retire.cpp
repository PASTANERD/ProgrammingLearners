//1759
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int schedule[16][2];
int ans = 0;
int n;

void check(int day, int sum){
    if(day == n+1){
       if(sum > ans) ans = sum;
       return;
    }
    if(day>n+1)
        return;
    
    check(day+1, sum);
    check(day+schedule[day][0], sum+schedule[day][1]);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> schedule[i][0] >> schedule[i][1];
    
    check(1,0);
    cout << ans << '\n';
}
