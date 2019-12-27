#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int *D = new int[n+1];
    D[1] = 1;
    D[2] = 2;

    for(int i=3; i<=n; i++){
        D[i] = (D[i-1]+D[i-2]) % 10007;
     }

    cout << D[n] << "\n";

    return 0;
}