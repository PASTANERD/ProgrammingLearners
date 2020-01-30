/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/10989
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

    int numbs[10001];
    fill_n(numbs, 10001, 0);
    

    for(int i = 0 ; i < N ; i++){
        int temp;
        cin >> temp;
        numbs[temp] += 1;
    }

    int j = 0;
    while(j < 10001){
        if(numbs[j] > 0){
            cout << j << '\n';
            numbs[j] -= 1;
        }
        else j++;
    }


    return 0;
}