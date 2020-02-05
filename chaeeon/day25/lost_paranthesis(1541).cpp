/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1541
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    cin >> N;

    string temp;
    vector<int> numbs;
    vector<char> opers;

    for(char c : N){
        if(c == '-' || c== '+'){
            numbs.push_back(stoi(temp));
            temp.clear();
            opers.push_back(c);
        }
        else{
            temp.push_back(c);
        }
    }
    numbs.push_back(stoi(temp));

    bool flag = false;
    int total = numbs[0];
    
    for(int i = 0 ; i < opers.size() ; i++){
        if(opers[i] == '+' && !flag){
            total +=numbs[i+1];
        }
        else{
            total -= numbs[i+1];
            flag = true;
        }
    }

    cout << total;
    
    return 0;
}