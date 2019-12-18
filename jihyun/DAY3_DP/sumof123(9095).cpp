
#include <iostream>

using namespace std;

int d[12] = {0,1,2,4,0};

int sub(int n){

    if(d[n] > 0)
        return d[n];
    
    d[n] = sub(n-1) + sub(n-2) + sub(n-3);
    return d[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int size;
    cin >> size;
    
    while(size--){
        int n;
        cin >> n;
        cout << sub(n) << '\n';
    }
}
