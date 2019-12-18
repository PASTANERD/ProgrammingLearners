/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1929
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;
    cin.ignore();
    int* primes;
    int pn = 0;
    bool* check;
    int n = A - B + 1;
    primes = (int*)malloc(sizeof(int)*n);
    check = (bool*)malloc(sizeof(bool)*n);
    for(int i = 2 ; i <= n ; i++){
        if(check[i] == false){
            primes[pn++] = i;
            for(int j = i*i ; j <= n ; j += i){
                check[j] = true;
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(check[i] == false) cout << primes[i]
    }
    return 0;
}