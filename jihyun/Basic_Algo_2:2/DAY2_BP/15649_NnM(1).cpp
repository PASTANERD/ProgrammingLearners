//15649 N&M(1)

#include<iostream>

using namespace std;

int ans[9];
bool used[9] = {false,};
int n,m;

void sub(int index){
    
    if(index == m){
        for(int i=0; i<m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    
    for(int i=1; i<=n; i++){
        if(!used[i]){
            ans[index] = i;
            used[i] = true;
            sub(index+1);
            used[i] = false;
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
