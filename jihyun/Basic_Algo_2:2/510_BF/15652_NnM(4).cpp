//15652 N&M(4)

#include<iostream>

using namespace std;

int ans[8];
int n,m;

void sub(int index){
    
    if(index == m){
        for(int i=0; i<m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    
    for(int i=1; i<=n; i++){
        if(index == 0 || ans[index-1] <= i){
            ans[index] = i;
            sub(index+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    
    sub(0);
}
