
/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/2529
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define SMAL false
#define BIGG true
using namespace std;

int N;

bool check(int *array, vector<char> ieq_list){
    for(int i = 0 ; i < N ; i++){
        if(ieq_list[i] == '<' && (array[i] > array[i+1])) return false;
        else if(ieq_list[i] == '>' && (array[i] < array[i+1])) return false;
    }
    return true;
}

unsigned long case_test(int *array, vector<char> ieq_list, bool flag){
    // unsigned int maximus = 0, minimus = 10000000000;
    unsigned long best = (flag ? 0 : ~0);
    do{
        // for(int i = 0 ; i < N; i++) cout << array[i] << ' ';
        
        if(check(array, ieq_list)){
            unsigned long temp = 0;
            unsigned long factor = 1;
            for(int i = 0 ; i <= N ; i++){
                temp = temp*10 + array[i];
                // if(array[i] == 0) temp
            }
            // cout << " --> temp: " << temp << " ";
            if(flag) best = max(best , temp);
            else best = min(best, temp);
        }
        // cout << "(best: " << best << ")";
        // cout << '\n';
    }while(next_permutation(array, array+(N+1)));

    return best;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<char> inequalities;
    for(int i = 0 ; i < N ; i++){
        char temp;
        cin >> temp;
        inequalities.push_back(temp);
    }
    int smalls[N+1];
    int biggie[N+1];
    
    for(int i = 0 ; i <= N ; i++){
        smalls[i] = i;
        biggie[i] = 9 - i;
    }
    sort(biggie, biggie+(N+1));

    cout << case_test(biggie, inequalities, BIGG) << '\n';

    string l = to_string(case_test(smalls, inequalities, SMAL));    
    if(l.length() < N+1) l = '0' + l;

    cout << l;
    
    return 0;
}
