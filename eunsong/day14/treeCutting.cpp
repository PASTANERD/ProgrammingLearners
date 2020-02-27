#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N, M;
bool check(vector<long long> &tree, long long h){
    long long cnt = 0;
    for(int i=0; i<tree.size(); i++){
        cnt += tree[i]-h;
    }
    return cnt >= M;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> N >> M;
    vector<long long> tree(N);

    for(int i=0; i<N; i++)
        cin >> tree[i];
    
    sort(tree.begin(), tree.end());
    long long left = 1, right = tree[N-1];
    long long h, ans = 0;

    while(left <= right){
        h = (left+right) / 2;
        if(check(tree, h)){
            ans = max(ans, h);
            left = h+1;
        }
        else{
            right = h-1;
        }
        cout << "h: " << h << "\n";
    }

    cout << ans << "\n";

    return 0;
}