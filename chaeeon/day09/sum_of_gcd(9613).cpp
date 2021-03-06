/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/9613
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/


#include <iostream>

using namespace std;

int get_gcd(int A, int B){
    if(B == 0){
        return A;
    }
    else return get_gcd(B, A%B);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();

    for(int i = 0 ; i < t; i++){
        int N;
        cin >> N;
        int *list = new int[N];
        for(int j = 0 ; j < N ; j++) cin >> list[j];
        
        long count = 0;
        for(int j = 0; j < N ; j++){
            for(int k = j+1; k < N; k++){
                count += get_gcd(list[j], list[k]);
            }
        }
        cout << count << '\n';
    }
    return 0;
}