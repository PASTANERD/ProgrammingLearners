/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/2309
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> dwarves;

    int temp;
    int sum = 0;

    for(int i = 0 ; i < 9 ; i++){ 
        cin >> temp;
        dwarves.push_back(temp);
        sum += temp;
    }

    int difference = sum - 100;

    for(auto itr = dwarves.begin() ; itr != dwarves.end() ; itr++){
        for(auto jtr = itr+1 ; jtr != dwarves.end() ; jtr++){
            if(*itr + *jtr == difference){
                dwarves.erase(itr);
                dwarves.erase(--jtr);
                break;
            }
        }
    }

    sort(dwarves.begin(), dwarves.end());

    for(vector<int>::iterator itr = dwarves.begin() ; itr != dwarves.end() ; itr++) cout << *itr << '\n';
    
    return 0;
}