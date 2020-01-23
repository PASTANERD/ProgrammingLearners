/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1931
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool sortBySecond(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second < b.second) return true;
    else if(a.second == b.second){
        return (a.first < b.first);
    }
    else return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    vector< pair<int,int> > schedule;

    for(int i = 0 ; i < N ; i++){
        int x, y;
        cin >> x >> y;
        schedule.push_back(make_pair(x, y));
    }
    sort(schedule.begin(), schedule.end(), sortBySecond);
    int count = 0;
    int max = 0;
    
    for(int i = 0 ; i < N ; i++){
        int start = schedule[i].first;
        int end = schedule[i].second;

        if(start >= max){
            max = end;
            count++;
        }
    }

    cout << count;

    return 0;
}