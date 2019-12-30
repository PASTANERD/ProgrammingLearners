/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/2193
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

/**
 * i = 1 일 때, i에서 만들 수 있는 가장 긴 부분 수열
 * i 부터 N까지 각각 가지는 가장 긴 부분수열 중 가잔 긴 부분 수열의 길이
 * i 번째 값을 선택하거나, 선택하지 않거나 할 수 있음.
 * 
 * i 번째 수가 포함되는 수열의 길이는 i 이전의 수를 포함하는 수열에서 1을 더하는 것
 * i가 수열의 시작점일 때, (예 i = 1) len[1] = 1, len[0] = 0
 * i = 2, len[2] = len[1] + 1 (if A[2] > A[1])
 * i = 3, len[3] = len[2] + 1 (if A[3] > A[2]) or len[2]+1 (A[3] =< A[2])
 * i = 4, len[4] = len[3] + 1 (if A[4] > A[3]) or len[2]+1 (A[3] =< A[4]) 
 * len[i] = max(len[i-1], len[i-2]) + 1
 * */


#include <iostream>
#include <vector>
#define PICKED 0
#define NOT_PICKED 1
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A;
    int temp;
    for(int i = 0 ; i < N ; i++) {
        cin >> temp;
        A.push_back(temp);
    }
    
    int **len = new int*[N+1];
    for(int i = 0 ; i <= N ; i++){
        len[i] = new int[2];
        fill_n(len[i], 2, 0);
    }
    temp = 0;
    int longest = 0;

    cout << longest << '\n';

    return 0;
}