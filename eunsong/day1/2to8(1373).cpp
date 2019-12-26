#include <iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int twoNum;
    cin >> twoNum;

    
    int count = 1;
    int eightNum = 0;
    
    while(twoNum > 0){
        if(twoNum % 10 == 1){
            eightNum += count;
        }
        count = count * 8;
        twoNum = twoNum / 10;
    }

    cout << eightNum << "\n";
   


    return 0;
}