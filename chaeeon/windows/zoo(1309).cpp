/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1309
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

/*
 * cage[N][S]: number of cases for lions (N: Nth row of cages, S: Status of cage -> E: empty, L: lion in LEFT cage, R: lion in RIGHT cage)
 * cage[1][E] = cage[1][L] = cage[1][R] = 1;
 * cage[N][E] = cage[N-1][E] + cage[N-1][L] + cage[N-1][R]
 * cage[N][L] = cage[N-1][E] + cage[N-1][R]
 * cage[N][R] = cage[N-1][E] + cage[N-1][L]
 * 
 */

#include <iostream>
#define E 0
#define L 1
#define R 2

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    int **cage = new int*[N+1];
     
    cage[0] = new int[3];
    cage[0] = {0,}; // not used

    cage[1] = new int[3];
    for(int i = 0 ; i <= 2; i++) cage[1][i] = 1; // Boundary Condition
    
    for(int i = 2; i <= N ; i++) {
        cage[i] = new int[3];
        cage[i][E] = (cage[i-1][E] + cage[i-1][L] + cage[i-1][R]) % 9901;
        cage[i][L] = (cage[i-1][E] + cage[i-1][R]) % 9901;
        cage[i][R] = (cage[i-1][E] + cage[i-1][L]) % 9901;
    }

    cout << (cage[N][E] + cage[N][L] + cage[N][R]) % 9901 << '\n';

    delete[] cage;

    return 0;
}