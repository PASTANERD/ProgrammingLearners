//15650 N&M(1)

#include<iostream>

using namespace std;

int ans[9];
bool used[9] = {false,};
int n,m;

void sub(int index, int data){
    
    if(index == m){
        for(int i=0; i<m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    
    for(int i=data; i<=n; i++){
        if(!used[i]){
            ans[index] = i;
            used[i] = true;
            sub(index+1, i);
            used[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    
    sub(0,1);
}
