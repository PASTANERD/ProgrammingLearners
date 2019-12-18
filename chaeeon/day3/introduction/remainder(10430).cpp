/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/10430
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;

    cout << (A+B) % C << '\n';
    cout << (A%C + B%C) % C << '\n';
    cout << (A*B) % C << '\n';
    cout << (A%C * B%C) % C << '\n';

    return 0;
}