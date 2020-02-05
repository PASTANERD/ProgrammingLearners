/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/11650
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool comp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first < b.first) return true;
    else if (a.first == b.first) return (a.second < b.second);
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int,int> > cod(N);

    for(int i = 0 ; i < N ; i++) cin >> cod[i].first >> cod[i].second;

    sort(cod.begin(), cod.end(), comp);

    for(int i = 0 ; i < N ; i++) cout << cod[i].first << ' ' << cod[i].second << '\n';
    return 0;
}