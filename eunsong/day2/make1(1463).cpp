#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;
    cin >> X;

    int *D = new int[X+1];
    D[1] = 0;

    for(int i=2; i<=X; i++){
        D[i] = D[i-1]+1;

        if(i%2 == 0 && D[i] > D[i/2]+1){
            D[i] = D[i/2] + 1;
           // cout << "2: "<<D[i]<<"\n";
        }
        if(i%3 == 0 && D[i] > D[i/3]+1){
            D[i] = D[i/3] + 1;
            //cout << "3: "<<D[i]<<"\n";
        }
    }
    
    cout << D[X] << "\n";

    return 0; 
}