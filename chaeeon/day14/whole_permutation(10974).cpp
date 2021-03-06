
/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/10974
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

    int N;
    cin >> N;

    int *arr = new int[N];
    for(int i = 0 ; i < N ; i++) arr[i] = (i+1);
    do{
        for(int i = 0 ; i < N; i++) cout << arr[i] << ' ';
        cout << '\n';
    }while(next_permutation(arr, arr+N));
    return 0;
}