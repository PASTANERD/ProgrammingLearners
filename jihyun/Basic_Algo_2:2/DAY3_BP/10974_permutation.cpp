//10974 permutation

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    vector<int> v;

    cin >> n;
    
    for(int i=1; i<=n; i++)
        v.push_back(i);
    
    do{
        for(auto i : v)
            cout << i << ' ';
        cout << '\n';
    }while(next_permutation(v.begin(), v.end()));
}
