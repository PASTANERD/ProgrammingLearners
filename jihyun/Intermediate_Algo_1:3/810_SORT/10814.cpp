
//10814
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool compare(tuple<int,int,string> a, tuple<int,int,string> b){
    if(get<1>(a) < get<1>(b)) return true;
    if(get<1>(a) > get<1>(b)) return false;
    return get<0>(a) < get<0>(b);
}

int main(){
    int n;
    cin >> n;
    vector< tuple<int,int,string> > v;
    
    for(int i=0; i<n; i++){
        int x;
        string y;
        cin >> x >> y;
        v.push_back({i,x,y});
    }

    sort(v.begin(),v.end(),compare);
    
    for(auto p : v)
        cout << get<1>(p) << ' ' << get<2>(p) << '\n';
}
