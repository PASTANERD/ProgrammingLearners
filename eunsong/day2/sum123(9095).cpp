#include <iostream>

using namespace std;


int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        int n;
        cin >> n;
        
        int D[11] = {0};
        D[0] = 1;

        for(int j=0; j<=n; j++){
            if(j-1>=0)
                D[j] += D[j-1];
            if(j-2>=0)
                D[j] += D[j-2];
            if(j-3>=0)
                D[j] += D[j-3];
        }

        cout << D[n] << "\n";
    }  

    return 0;
} 