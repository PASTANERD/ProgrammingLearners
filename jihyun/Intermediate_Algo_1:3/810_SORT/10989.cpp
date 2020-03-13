
//10989
#include <iostream>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int num[10001] = {0,};
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        num[x]++;
    }

    int total = 0;
    for(int i=1; i<10001; i++){
        if(num[i]==0) continue;
        if(total>=n) break;
        int cnt = num[i];
        while(cnt--){
            cout << i << '\n';
            total ++;
        }
    }
}

