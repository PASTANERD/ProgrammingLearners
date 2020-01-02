#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    sort(a.begin(), a.end());
    
    int answer = 0;
    do{
        int sum = 0;
        for(int i=1; i<n; i++){
            sum += abs(a[i]-a[i-1]);
        }
        //cout << sum << endl;
        answer = (sum > answer) ? sum : answer;
    }while(next_permutation(a.begin(), a.end()));

    cout << answer << "\n";

    return 0;
}