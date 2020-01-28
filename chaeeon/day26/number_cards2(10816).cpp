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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;

    int n_cards[N];
    for(int i = 0 ; i < N ; i++) cin >> n_cards[i];

    sort(n_cards, n_cards+N);

    cin >> M;
    int m_cards[M];
    for(int i = 0 ; i < M ; i++) cin >> m_cards[i];

    int count[M];
    fill_n(count, M, 0);    

    for(int i = 0 ; i < M ; i++){
        int cur_m = m_cards[i];
        int left = 0, right = N-1;
        int lower_bound = -1;
        while(left <= right){
            int mid = (left+right)/2;
            if(n_cards[mid]  == cur_m){
                lower_bound = mid;
                right = mid-1;
            }
            else if (n_cards[mid] > cur_m){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        
        left = 0, right = N-1;
        int upper_bound = -1;
        while(left <= right){
            int mid = (left+right)/2;
            if(n_cards[mid]  == cur_m){
                upper_bound = mid;
                left = mid+1;
            }
            else if (n_cards[mid] > cur_m){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        if(upper_bound >= 0 && lower_bound >= 0){
            count[i] = upper_bound - lower_bound + 1;
        }
    }

    for(int i = 0 ; i < M ; i++){
        cout << count[i] << ' ';
    }

    return 0;
}