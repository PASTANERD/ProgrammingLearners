/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1790
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

    int N, k;
    cin >> N >> k;

    int total = 0;
    // 자릿수 카운트
    int i=1, l=1;
    int lb = 1, ub = 0;
    for(; ; i *=10, l +=1 ){
        lb += i*9/10*(l-1);
        ub = lb + 9*i*l - 1;
        if(10*i <= N) total += 9*i*l;
        else if (i <= N && N < 10*i) total+= (N-i+1)*l;
        if(k < ub) break;
    }

    // cout << "total         : " << total << '\n';
    // cout << "lower bound   : " << lb << '\n';
    // cout << "upper bound   : " << ub << '\n';
    // cout << "number length : " << l << '\n';

    if(k > total){
        cout << "-1" << '\n';
        return 0;
    }
    int number = i + (k-lb)/l;

    // cout << "number        : " << number << '\n';
    // cout << "kth index     : " << (k-lb)%l << '\n';

    int answer;
    for(int c = l ; c > (k-lb)%l ; c--){
        answer = number%10;
        number /= 10;
    }
    // cout << number << '\n';
    cout << answer << '\n';

    return 0;
}