/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/10820
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string N;
    int capital, small, number, space;
    
    while(getline(cin,N)){
        capital = 0;
        small = 0;
        number = 0;
        space = 0;
        for(string::iterator itr = N.begin() ; itr != N.end() ; itr++){
            if(*itr >= '0' && *itr <= '9') number++;
            else if(*itr >= 'a' && *itr <= 'z') small++;
            else if(*itr >= 'A' && *itr <= 'Z') capital++;
            else if(*itr == ' ') space++;
        }
        cout << small << " " << capital << " " << number << " " << space << '\n';
    }   
    return 0;
}