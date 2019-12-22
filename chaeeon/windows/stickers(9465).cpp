/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/9465
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

/*
 * 
 *  
 */
incompleted
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    cout << (N*(N+1)+1) % 9901 << '\n';

    return 0;
}