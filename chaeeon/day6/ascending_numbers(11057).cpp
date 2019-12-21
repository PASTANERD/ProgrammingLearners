/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/11057
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

/*
 * asc[N][D]: number of cases for N digits with D (in 0 ~ 9) in N-1 position
 * asc[N][0] = asc[N-1][0]
 * asc[N][1] = asc[N-1][1] + asc[N-1][0]
 * ...
 * asc[N][9] = asc[N-1][9] + asc[N-1][8] + ... asc[N-1][0]
 * 
 * =>
 * asc[N][0] = asc[N-1][0]
 * asc[N][i] = asc[N-1][i] + asc[N][i-1] (i>0)
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

    unsigned int **asc = new unsigned int*[N+1];
    
    asc[0] = new unsigned int[10];
    asc[1] = new unsigned int[10];
    for(int i = 0; i <= 9; i++){
        asc[0][i] = 0;
        asc[1][i] = 1;
    }
    for(int i = 2; i <= N ; i++) {
        asc[i] = new unsigned int[10];
        asc[i][0] = asc[i-1][0];
        for(int j = 1; j <= 9 ; j++){
            asc[i][j] = (asc[i-1][j] + asc[i][j-1]) % 10007;
        }
        
    }
    int answer = 0;
    for(int i = 0 ; i <=9 ; i++) answer += asc[N][i];
    cout << answer  % 10007 << '\n';
    
    delete[] asc;
    return 0;
}