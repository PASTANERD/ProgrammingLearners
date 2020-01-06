/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/2609
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, a, b;
    cin >> A >> B;

    int gcd = 1;
    a = A; 
    b = B;
    // Normal calculation
    // for (int i = 2 ; i <= min(a,b) ; i++) if(a % i == 0 && b % i == 0) gcd = i;
    
    // Eucleadian Algorithm
    int temp;
    while(b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    gcd = a;


    int lcm = 1;
    a = A; 
    b = B;

    // Normal calculation
    // for(int i = max(a,b) ; i <= a*b ; i++) {
    //     if(i%a == 0 && i%b == 0){
    //         lcm = i;
    //         break;
    //     } 
    // }
    
    // Using GCD
    lcm = a*b/gcd;

    cout << gcd << '\n';
    cout << lcm << '\n';
    return 0;
}