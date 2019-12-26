/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/10824
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << stoll((A+B))+stoll((C+D)) << '\n';
    return 0;
}

/**
 * 10 20 30 40
 * 1020 + 3040
 * 4060
 */