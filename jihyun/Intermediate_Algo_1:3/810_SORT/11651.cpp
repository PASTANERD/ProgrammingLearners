//11651
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second < b.second) return true;
    if(a.second > b.second) return false;
    return (a.first < b.first);
    
}

int main(){
    int n;
    cin >> n;
    vector< pair<int,int> > v;
    
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    sort(v.begin(),v.end(),cmp);
    
    for(auto p : v)
        cout << p.first << ' ' << p.second << '\n';
}


