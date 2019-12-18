/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/11576
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

    int A, B, lsb;
    cin >> A >> B;
    cin.ignore();
    
    int n_A;
    cin >> n_A;
    cin.ignore();

    int N;
    int decimal = 0;
    for(int i = 0 ; i < n_A ; i++){
        cin >> N;
        decimal = decimal*A + N;
    }

    string answer ="";

    while(decimal > 0){
        lsb = decimal%B;
        decimal = decimal/B;
        answer = to_string(lsb) + " " + answer;
    }
    answer.pop_back();
    cout << answer << '\n';

    return 0;
}