#include <iostream>
#include <vector>

using namespace std;
int ans, n;
int **s;
int go(int index, vector<int> &first, vector<int> &second){
    if(index > n)   return;
    if(first.size() > n/2 || second.size() > n/2) return;
    if(index == n){
        int t1, t2=0;
        t1 = first.back();
        t2 = second.back();
        if(ans > abs(t1-t2)){
            ans = abs(t1-t2);
            cout << ans << "\n";
            first.pop_back();
            second.pop_back();
        }
    }
    for()
        
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    s = new int*[n];
    for(int i=0; i<n; i++)
        s[i] = new int[n]; 
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> s[i][j];

    vector<int> first(n/2), second(n/2);
    go(0, first, second);

    cout << ans << "\n";
    return 0;
}