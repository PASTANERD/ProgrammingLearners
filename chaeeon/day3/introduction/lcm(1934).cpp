/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1934
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>

using namespace std;

int myGCD(int A, int B){
    if(B == 0){
        return A;
    }
    else{
        return myGCD(B, A%B);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore();

    int gcd = 1;
    int A, B;
    int lcm;
    for(int i = 0 ; i < T ; i++){
        cin >> A >> B;
        gcd = myGCD(A, B);
        lcm = A*B/gcd;
        cout << lcm << '\n';
    }
    
    return 0;
}