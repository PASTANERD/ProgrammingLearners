/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1212
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/


#include <iostream>

using namespace std;

string oct2bin(char ch){
    if(ch == '0') return "000";
    else if (ch == '1') return "001";
    else if (ch == '2') return "010";
    else if (ch == '3') return "011";
    else if (ch == '4') return "100";
    else if (ch == '5') return "101";
    else if (ch == '6') return "110";
    else if (ch == '7') return "111";
    else return "???";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string octal;
    int init = 0;
    cin >> octal;
    if(octal[0] < '4'){
        init = 1;
        char first = octal[0];
        switch(first){
            case '0':
                cout << "0";
                break;
            case '1':
                cout << "1";
                break; 
            case '2':
                cout << "10";
            break;
            case '3':
                cout << "11";
            break;
        }
    }
    
    for(string::iterator itr = octal.begin() + init ; itr != octal.end() ; itr++){
        cout << oct2bin(*itr);
    }

    return 0;
}
