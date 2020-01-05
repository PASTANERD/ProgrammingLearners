/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/17087
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/


#include <iostream>

using namespace std;

int get_gcd(int A, int B){
    if(B == 0) return A;
    else return get_gcd(B, A%B);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;

    int *Ai = new int[N];
    int *distance = new int[N];
    for(int i = 0 ; i < N ; i++) {
        cin >> Ai[i];
        distance[i] = abs(Ai[i] - S);
    }

    int D = distance[0];
    for(int i = 1 ; i < N; i++) D = get_gcd(D, distance[i]);

    cout << D << '\n';
    
    return 0;
}