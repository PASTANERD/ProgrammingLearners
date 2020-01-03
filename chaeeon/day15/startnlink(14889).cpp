/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/14889
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <algorithm>

using namespace std;


int N;
int *T, *P;

int make_money(int sum, int day){
    if(day == N) return sum;
    if(day > N) return 0;
    else return max(make_money(sum+P[day], day+T[day]), make_money(sum, day+1));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    T = new int[N];
    P = new int[N];
    for(int i = 0 ; i < N ; i++) cin >> T[i] >> P[i];
    
    cout << make_money(0, 0);

    return 0;
}
