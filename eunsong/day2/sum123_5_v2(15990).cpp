#include <iostream>

using namespace std;

#define MAX 100000
const int mod = 1000000009;
long D[MAX][4];

int sum(int N){
    return (D[N][1] + D[N][2] + D[N][3]) % mod;
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T, n;
    cin >> T;

    //memoization
    for(int i=0; i<=MAX; i++)
        fill_n(D[i], 4, -1);

    D[1][1] = 1;
    D[1][2] = 0;
    D[1][3] = 0;
    D[2][1] = 0;
    D[2][2] = 1;
    D[2][3] = 0;
    D[3][1] = 1;
    D[3][2] = 1;
    D[3][3] = 1;


    for(int i=0; i<T; i++){
        cin >> n; 

        if(sum(n)>0)    cout << sum(n) << "\n";  
        else{
            for(int j=4; j<=n; j++){
            if(D[j][1] == -1){
                D[j][1] = (D[j-1][2] + D[j-1][3]) % mod;
                //cout << "D[" <<  j << "][1]: " << D[j][1] << endl;
            }
            if(D[j][2] == -1){
                D[j][2] = (D[j-2][1] + D[j-2][3]) % mod ;
                //cout << "D[" <<  j << "][2]: "<< D[j][2] << endl;
            }
            if(D[j][3] == -1){
                D[j][3] = (D[j-3][1] + D[j-3][2]) % mod;
                //cout << "D[" <<  j << "][3]: "<< D[j][3] << endl;
            }
        }
        cout << sum(n) << "\n";
        }
    }  

    return 0;
}