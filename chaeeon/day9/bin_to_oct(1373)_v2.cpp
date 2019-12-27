/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1373
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/


#include <iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string Binary;
    cin >> Binary;

    int decimal = 0;
    while(Binary.length() > 0){
        decimal = decimal*2 + (Binary.front() - '0');
        Binary = Binary.substr(1);
    }
    cout << "decimal : " << decimal << '\n';
    string oct;

    while(decimal > 0){
        oct.push_back(decimal % 8 + '0');
        decimal /= 8;
    }
    cout << "r_oct : " << oct << '\n';
    for(string::iterator itr = oct.end()-1 ; itr != oct.begin()-1 ; itr--) cout << *itr;

    
    return 0;
}