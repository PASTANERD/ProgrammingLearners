#include <iostream>

using namespace std;

void DecToOcta(int n){
    if(n == 0) return;
    else{
        DecToOcta(n/8);
        cout << n%8;
    }
}

int main(){
        ios_base:: sync_with_stdio(false);
        cin.tie(nullptr);

        int twoNum;
        cin >> twoNum;      // twoNum = 11001100

        int count = 1;      // num of position
        int decimal = 0;   // oct values
        
        while(twoNum > 0){
            if(twoNum % 10 == 1){   // 11001100 --> 0th pos : 0
                decimal += count;
                //cout << eightNum << endl;
            }
            count = count * 2;      // ith pos : (0 or 1) * 2^i
            twoNum = twoNum / 10;
            //cout << "count:" << count << endl;
        }
        cout << decimal << "\n";
       DecToOcta(decimal);

        cout << "\n";
    

    return 0;
}