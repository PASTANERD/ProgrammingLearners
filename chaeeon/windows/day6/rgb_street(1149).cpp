/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1149
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

/*
 * cost[N][C]: minimum cost to paint for all N houses with color C
 * paint[C]: price of paint color (R, G, B)
 * cost[N][R] = min(cost[N-1][G], cost[N-1][B]) + paint[N][R]
 * cost[N][G] = min(cost[N-1][R], cost[N-1][B]) + paint[N][G]
 * cost[N][B] = min(cost[N-1][R], cost[N-1][G]) + paint[N][B] 
 */

#include <iostream>
#define R 0
#define G 1
#define B 2
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    unsigned int **cost = new unsigned int*[N+1];
    unsigned int **paint = new unsigned int*[N+1];
    unsigned int nr, ng, nb;    
    cost[0] = new unsigned int[3];
    paint[0] = new unsigned int[3];
    paint[0] = {0,};    
    cost[0] = {0,};


    for(int i = 1; i <= N ; i++) {
        cost[i] = new unsigned int[3];
        paint[i] = new unsigned int[3];
        cin >> nr >> ng >> nb;
        paint[i][0] = nr;
        paint[i][1] = ng;
        paint[i][2] = nb;
    }

    // Boundary Condition
    cost[1][R] = paint[1][R];
    cost[1][G] = paint[1][G];
    cost[1][B] = paint[1][B];

    for(int i = 2; i <= N ; i++){
        cost[i][R] = min(cost[i-1][G], cost[i-1][B]) + paint[i][R];
        cost[i][G] = min(cost[i-1][R], cost[i-1][B]) + paint[i][G];
        cost[i][B] = min(cost[i-1][R], cost[i-1][G]) + paint[i][B] ;
    }

    cout << min(min(cost[N][R], cost[N][G]), cost[N][B]) << '\n';

    delete[] cost;
    delete[] paint;
    return 0;
}