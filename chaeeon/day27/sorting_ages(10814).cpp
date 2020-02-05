/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/11651
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

bool comp(const tuple<int,int, string> &a, const tuple<int,int, string> &b){
    if(get<1>(a) < get<1>(b)) return true;
    else if (get<1>(a) == get<1>(b)) return (get<0>(a) < get<0>(b));
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<tuple<int,int,string> > member;

    for(int i = 0 ; i < N ; i++){
        int age; string name;
        cin >> age >> name;
        member.push_back(make_tuple(i, age, name));
    }

    sort(member.begin(), member.end(), comp);

    for(int i = 0 ; i < N ; i++) cout << get<1>(member[i]) << ' ' << get<2>(member[i]) << '\n';

    return 0;
}