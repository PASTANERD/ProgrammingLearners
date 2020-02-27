#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*array reference로 어떻게 받지? 
*   int &x[]?
*/

bool check(vector<int> &x, int c, int distance){
    int cnt = 1;
    int last = x[0];
    for(int house: x){
        if(house - last >= distance){
            cnt += 1;
            last = house;
        }
    }
    return cnt >= c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, C;
    cin >> N >> C;

    vector<int> x(N);
    for(int i=0; i<N; i++)
        cin >> x[i];

    sort(x.begin(), x.end());
    int left = 0;
    int right = x[N-1] - x[0];

    int ans = left;
    while(left <= right){
        int mid = (left + right)/2;
        if(check(x, C, right)){
            if(ans < mid)
                ans = mid;
            left = mid+1;                
        }else{
            right = mid-1;
        }
    }

    cout << ans << "\n";

    return 0;
}



