/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/10819
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
    int sum = 0, best = 0;
    for(int i = 0 ; i < N ; i++) cin >> arr[i];
    sort(arr, arr+N);
    do{
        for(int i = 0 ; i < N-1 ; i++) sum += abs(arr[i] - arr[i+1]);
        best = max(best, sum);
        sum = 0;
    }while(next_permutation(arr, arr+N));

    cout << best;

    return 0;
}

/**
 * 3 8 10 29 7 1
 * 3-8 = 5
 * 5-10 = 2
 * |10 - 29| = 19
 * */