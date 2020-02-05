/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/10816
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/


/**
 * 상근이가 가진 값을 소팅한다.
 * M개의 숫자 카드에 대해 상근이가 가진 카드에서
 * 이분탐색으로 상한과 하한을 구한다.
 * 
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int binary_search(int* n_cards, int cur_m){
    int left = 0, right = N-1;
    while(left <= right){
        int mid = (left+right)/2;
        if(n_cards[mid]  == cur_m){
            return 1;
        }
        else if (n_cards[mid] > cur_m){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    int n_cards[N];
    for(int i = 0 ; i < N ; i++) cin >> n_cards[i];

    sort(n_cards, n_cards+N);

    cin >> M;
    for(int i = 0 ; i < M ; i++){
        int m_card;
        cin >> m_card;
        cout << binary_search(n_cards, m_card) << ' ';
    }
    return 0;
}