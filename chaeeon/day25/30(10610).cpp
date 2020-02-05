/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1541
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    cin >> N;

    bool isZero = false;
    int total = 0;

    for(char c : N){
        total += (c - '0');
        if(c == '0') isZero = true;
    }

    if(total % 3 != 0 || !isZero){
        cout << -1;
        return 0;
    }
    else{
        sort(N.begin(), N.end(),greater<char>());
        cout << N;
    }

    return 0;
}