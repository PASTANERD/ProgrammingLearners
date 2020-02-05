#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;

    int n_2 = n/2;
    int n_teams = min(n_2, m);

    int reservoir = n + m - n_teams * 3;

    int diff = k - reservoir;

    if(diff <= 0){
        cout << n_teams;
    }
    else{
        int answer = n_teams - ((diff-1) / 3 + 1);
        cout << (answer > 0 ? answer : 0);
    }

    return 0;
}