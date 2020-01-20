
/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/14888
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int *numbs;

void possible_cases(int index, vector<int> &lotto){
    if(lotto.size() == 6) {
        for(vector<int>::iterator itr = lotto.begin() ; itr != lotto.end() ; itr++) cout << *itr << ' ';
        cout << '\n';
        return;    
    }
    if(index >= N) return;
    else{
        lotto.push_back(numbs[index]);
        possible_cases(index+1, lotto);
        lotto.pop_back();
        possible_cases(index+1, lotto);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    do{
        cin >> N;
        if(N == 0) break;
        else{
            numbs = new int[N];
            for(int i = 0 ; i < N ; i++){
                cin >> numbs[i];
            }
            vector<int> lotto;
            possible_cases(0, lotto);
            cout << '\n';
        }
    }while(true);

    return 0;
}