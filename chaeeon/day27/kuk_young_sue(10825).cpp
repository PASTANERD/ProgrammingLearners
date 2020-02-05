/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/10825
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

bool comp(const tuple<string,int,int,int> &a, const tuple<string,int,int,int> &b){
    if(get<1>(a) > get<1>(b)) return true;
    else if (get<1>(a) == get<1>(b)){
        if(get<2>(a) < get<2>(b)) return true;
        else if (get<2>(a) == get<2>(b)){
            if(get<3>(a) > get<3>(b)) return true;
            else if(get<3>(a) == get<3>(b)){
                return (get<0>(a) < get<0>(b));
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<tuple<string,int,int,int> > student;

    for(int i = 0 ; i < N ; i++){
        string name; int kuk, young, sue;
        cin >> name >> kuk >> young >> sue;
        student.push_back(make_tuple(name, kuk, young, sue));
    }

    sort(student.begin(), student.end(), comp);

    for(int i = 0 ; i < N ; i++) cout << get<0>(student[i]) << '\n';

    return 0;
}