
/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1339
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<char> alphabets;
// char id;

long long get_number(int* number, string word){
    long long temp = 0;
    for(int i = 0 ; i < word.length() ; i++){
        // int id;
        // int j = 0;
        // for(auto itr = alphabets.begin() ; itr != alphabets.end() ; itr++){
        // if(*itr == word[i]){
        //     id = 
        // }
        // }
        int id = distance(alphabets.begin(), find(alphabets.begin(), alphabets.end(), word[i]));
        temp = temp*10 + number[(int)(word[i]-id)];
    }
    // cout << temp << '\n';
    return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    string a[N];
    for(int i = 0 ; i < N ; i++) cin >> a[i];

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < a[i].length() ; j++){
            alphabets.push_back(a[i][j]);
        }
    }
    sort(alphabets.begin(), alphabets.end());       // 1 1 2 2 3 3 3
    alphabets.erase(unique(alphabets.begin(), alphabets.end()), alphabets.end()); // 1 2 3 ? ? ? return 첫번쨰 ? itrerator
    // id = alphabets[0];
    // A B -- Z;    // 1 2 3 
    int numbers[alphabets.size()];
    for(int i = 0 ; i < alphabets.size() ; i++) numbers[i] = 9 - i; // cout << alphabets[i];

    long long best = 0;

    do{
        long long temp = 0;
        for(int i = 0 ; i < N ; i++){
            temp = temp + get_number(numbers, a[i]);
        }
        best = max(temp, best);
    }while(prev_permutation(numbers, numbers + alphabets.size()));

    cout << best; 

    return 0;
}
