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

    string binary;
    cin >> binary;
    
    int init = binary.length() % 3;

    if(init == 1){
        if(binary[0] == '0') cout << '0';
        else if(binary[0] == '1') cout << '1';
        else cout << '?';
    }
    else if(init == 2){
        if(binary[0] == '0' && binary[1] == '0') cout << '0';
        else if(binary[0] == '0' && binary[1] == '1') cout << '1';
        else if(binary[0] == '1' && binary[1] == '0') cout << '2';
        else if(binary[0] == '1' && binary[1] == '1') cout << '3';
        else cout << '?';
    }
    string three = "";
    
    for(string::iterator itr = binary.begin() + init ; itr != binary.end() ; itr += 3){
    
        three.push_back(*itr);
        three.push_back(*(itr+1));
        three.push_back(*(itr+2));
        
        cout << bin2oct((three));
        
        three.erase();
    }

    return 0;
}
