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
    
    // cin >> N;
    getline(cin, N);
    
    for(string::iterator itr = N.begin() ; itr != N.end() ; itr++){
        if(*itr >= 'a' && *itr<='z') cout << (*itr+13 <= 'z' ? (char)(*itr+13):(char)(*itr+13 - 'z' + 'a' - 1));
        else if(*itr >= 'A' && *itr<='Z') cout << (*itr+13 <= 'Z' ? (char)(*itr+13):(char)(*itr+13 - 'Z' + 'A' - 1));
        else cout << *itr;
    }
    
    return 0;
}