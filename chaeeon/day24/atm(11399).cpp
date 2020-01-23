/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1931
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

    int people[N];
    for(int i = 0 ; i < N ; i++) cin >> people[i];

    sort(people, people+N);

    int count = 0;
    for(int k = 0 ; k < N ; k++){
        for(int i = 0 ; i <= k ; i++){
            count += people[i];
        }
    }

    cout << count;
    
    return 0;
}