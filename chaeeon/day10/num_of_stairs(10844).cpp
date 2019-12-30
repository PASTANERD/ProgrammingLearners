/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/10844
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

/*
 * stairs[N][D] = stairs[N-1][D-1] + stairs[N-1][D+1]
 * if N = 1, D = {1, ... , 9}
 * else D = {0, ... , 9}
 * 
 */

#include <iostream>
#define MODULAR 1000000000

using namespace std; 

int *memo;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    unsigned int **stairs = new unsigned int*[N];
    stairs[0] = new unsigned int[10];
    fill_n(stairs[0], 10, 1);
    stairs[0][0] = 0;
    for(int i = 1 ; i < N ; i++){
        stairs[i] = new unsigned int[10];
        fill_n(stairs[i], 10, 0);
    }

    for(int i = 1; i < N ; i++){
        stairs[i][0] = stairs[i-1][1] % MODULAR;
        for(int j = 1; j <= 8; j++){
            stairs[i][j] = (stairs[i-1][j-1] + stairs[i-1][j+1]) % MODULAR;
        }
        stairs[i][9] = stairs[i-1][8] % MODULAR;
    }

    unsigned int sum = 0;
    for(int i = 0; i <= 9; i++) {
        sum += stairs[N-1][i];
        sum %= MODULAR; 
    }
    
    cout << sum;

    return 0;
}