/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/16194
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

/*
 *  price(N): The biggest cost for buying cards
 *  price(N) = max(cards[N], cards[N-i] price(i))
 */

#include <iostream>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    int *cards = (int*)calloc(N+1, sizeof(int));
    for(int i = 1 ; i <= N ; i++) cin >> cards[i];
    
    int *cost = (int*)calloc(N+1, sizeof(int));
    for(int i = 1 ; i <= N ; i++) cost[i] = 10001;

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= i ; j++){
            cost[i] = min(cost[i], cost[i-j]+cards[j]);
        }
    }

    cout << cost[N];
    return 0;
}