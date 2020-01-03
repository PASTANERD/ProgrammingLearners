/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1759
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>

using namespace std;

regex vowel("[aeiou]+");
regex consonant("[aeiou]*[^aeiou]+[aeiou]*[^aeiou]+[aeiou]*");

void check(string password){
    if(regex_search(password, vowel) && regex_search(password, consonant)) cout << password << '\n';
}

void get_cases(string password, vector<char> &alphabet, int index, int L){
    if(password.size() == L){
        check(password);
        return;
    }
    if(index >= alphabet.size()) return;
    else{
        password.push_back(alphabet[index]);
        get_cases(password, alphabet, index+1, L);
        password.pop_back();
        get_cases(password, alphabet, index+1, L);
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, C;
    cin >> L >> C;

    vector<char> alphabet;
    char temp;
    for(int i = 0 ; i < C ; i++){
        cin >> temp;
        alphabet.push_back(temp);
    }

    sort(alphabet.begin(), alphabet.end());

    get_cases("", alphabet, 0, L);

    return 0;
}
