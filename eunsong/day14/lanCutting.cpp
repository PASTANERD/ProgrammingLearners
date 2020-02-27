#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
bool check(vector<long long>& lan, long long x){
    long long cnt = 0;
    for(int i=0; i<K; i++){
        cnt += lan[i]/x;
    }
    //cout << "cnt: " << cnt << "\n";
    return cnt >= N;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> K >> N;

    vector<long long> lan(K);
    for(int i=0; i<K; i++){
        cin >> lan[i];
    }

    sort(lan.begin(), lan.end());
    /*for(int i=0; i<K; i++)
        cout << "lan[" << i << "]: " <<lan[i] << "\n";
    */

    long long left = 1, right = lan[K-1];
    long long ans = 0, mid = 0;

    while(left <= right){
        mid = (left+right) / 2;
        if(check(lan, mid)){
            if(ans < mid){
                ans = mid;
            }
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    cout << ans << "\n";
    /*
    * 4 11
    * 802 743 457 539
    * 457 / 2 
    * mid = 200
    * 100 cnt > N
    * 
    * 1 100 50 x
    * 1 50
    * 50 100
    * l=1 r=399
    * mid = 200
    * left = 2, 3 ,4
    * mid = 201, 202 
    * cnt < N
    * */


    return 0;
}