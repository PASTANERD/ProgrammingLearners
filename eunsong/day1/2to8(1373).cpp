#include <iostream>

using namespace std;

#define MAX 1000000

int main(){
    try{
         int twoNum;
        cin >> twoNum;

        if(twoNum >= MAX)
            throw twoNum;

        int count = 1;
        int eightNum = 0;
        
        while(twoNum > 0){
            if(twoNum % 10 == 1){
                eightNum += count;
                //cout << eightNum << endl;
            }
            count = count * 8;
            twoNum = twoNum / 10;
            //cout << "count:" << count << endl;
        }

        cout << eightNum << endl;
    }catch(int excp){
        cout << "[error: out of bound]: " << excp << endl;  
    }


    return 0;
}