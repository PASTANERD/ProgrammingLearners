/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1373
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/


#include <iostream>

using namespace std;

char bin2oct(string str){
    if(str == "000") return '0';
    else if(str == "001") return '1';
    else if(str == "010") return '2';
    else if(str == "011") return '3';
    else if(str == "100") return '4';
    else if(str == "101") return '5';
    else if(str == "110") return '6';
    else if(str == "111") return '7';
    else return '?';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string Binary;
    cin >> Binary;

    string three;
    if(Binary.length() % 3 > 0){
        three = Binary.substr(0, Binary.length()%3);
        if(three == "0" || three ==  "00") cout << '0';
        else if(three == "1" || three ==  "01") cout << '1';
        else if(three == "10") cout << '2';
        else if(three == "11") cout << '3';
        else cout << '?';
        Binary = Binary.substr(Binary.length()%3);
    }
    while(Binary.length() > 0){
        three = Binary.substr(0, 3);
        Binary = Binary.substr(3);
        cout << bin2oct(three);
    }
    
    return 0;
}

/**
 * input : 11001100
 * 11 001 100
 * 3    1   4 
 */