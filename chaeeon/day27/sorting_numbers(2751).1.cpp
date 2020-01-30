/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/2751
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int numbs[2000001];
    fill_n(numbs, 2000001, 0);
    
    for(int i = 0 ; i < N ; i++){ 
        int temp;
        cin >> temp;
        numbs[1000000 + temp] = 1;
    }

    for(int i = -1000000 ; i <= 1000000 ; i++){
        if(numbs[1000000+i] == 1) cout << i << ' ';
    }


    return 0;
}