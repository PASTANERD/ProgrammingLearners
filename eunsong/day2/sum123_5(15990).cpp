#include <iostream>

using namespace std;

const int mod = 1000000009;

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        int n;
        cin >> n; 
        
        int D[11][4];
        D[0][1] = D[0][2] = D[0][3] = 0;
        D[1][1] = D[2][2] = D[3][1] = D[3][2] = D[3][3] = 1;
        D[1][2] = D[1][3] = D[2][1] = D[2][3] = 0; 

        for(int j=3; j<=n; j++){
            if(j-1>=0){
                D[j][1] = (D[j-1][2] + D[j-1][3]) % mod;
                cout << "D[" <<  j << "][1]: " << D[j][1] << endl;
            }
            if(j-2>=0){
                D[j][2] = (D[j-1][1] + D[j-1][3]) % mod ;
                cout << "D[" <<  j << "][2]: "<< D[j][2] << endl;
            }
            if(j-3>=0){
                D[j][3] = (D[j-1][1] + D[j-1][2]) % mod;
                cout << "D[" <<  j << "][3]: "<< D[j][3] << endl;
            }
        }

        cout << D[n][1] + D[n][2] + D[n][3] << "\n";
    }  

    return 0;
}