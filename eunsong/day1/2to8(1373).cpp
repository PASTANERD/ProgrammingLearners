#include <iostream>

using namespace std;

#define MAX 1000000

int main(){
        int twoNum;
        cin >> twoNum;      // twoNum = 11001100

        int count = 1;      // num of position
        int eightNum = 0;   // oct values
        
        while(twoNum > 0){
            if(twoNum % 10 == 1){   // 11001100 --> 0th pos : 0
                eightNum += count;
                //cout << eightNum << endl;
            }
            count = count * 2;      // ith pos : (0 or 1) * 2^i
            twoNum = twoNum / 10;
            //cout << "count:" << count << endl;
        }

        cout << eightNum << endl;
    // }catch(int excp){
    //     cout << "[error: out of bound]: " << excp << endl;  
    // }


    return 0;
}