/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/17103
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/


#include <iostream>
#define N 1000000

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int *prime = new int[N+1];

    // make primes
    prime[0] = 0;
    prime[1] = 0;
    // for(int i = 2 ; i < N ; i++) prime[i] = i;
    // for(int i = 2 ; i < N ; i++){
    //     if(prime[i] == 0) continue;
    //     else {
    //         for(int j = i+1 ; j < N ; j++){
    //             if(prime[j] == 0) continue;
    //             else if(prime[j] % 2 == 0) prime[j] = 0; 
    //         }
    //     }
    // }

    for(int i = 2; i < N+1 ; i++){
        for(int j = i+1; j < N+1 ; j++){
            if(prime[j] == 0) continue;
            else {
                prime[i] = i;
                if(j % i == 0) prime[j] = 0;
            }
        }
    }

    for(int i = 2; i < N+1; i++) if(prime[i] != 0) cout << prime[i] << " ";

    // int T;
    // cin >> T;

    // for(int i = 0; i < T; i++){
    //     int n;
    //     cin >> n;
    //     int count = 0;
    //     for(int j = 2; j < n; j++){
    //         if(prime[j] != 0 && prime[n-j] != 0){
    //             if(n == (prime[j] + prime[n-j])) count++;
    //         }
    //     }
    //     cout << count << '\n';
    // }
    return 0;
}