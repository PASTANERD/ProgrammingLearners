#include <iostream>
#include <string>


using namespace std;

void first(char a){
    switch(a - '0'){
        case 1: cout << "1"; break;
        case 2: cout << "10"; break;
        case 3: cout << "11"; break;
        case 4: cout << "100"; break;
        case 5: cout << "101"; break;
        case 6: cout << "110"; break;
        case 7: cout << "111"; break;
    }
}

void trans(char a){
    switch(a - '0'){
        case 1: cout << "001"; break;
        case 2: cout << "010"; break;
        case 3: cout << "011"; break;
        case 4: cout << "100"; break;
        case 5: cout << "101"; break;
        case 6: cout << "110"; break;
        case 7: cout << "111"; break;
    }
}

int main(){
    string eightNum;
    cin >> eightNum;

    int num = atoi(eightNum.c_str());
    
    int len;
    len = eightNum.length();
    for(int i = 0; i < len; i++){
        if(i == 0)
            first(eightNum[i]);
        else
            trans(eightNum[i]);
    }
    cout << endl;


    return 0;

}