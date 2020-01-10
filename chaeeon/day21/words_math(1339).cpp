
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

int get_number(int* number, string word){
    int temp = 0;
    for(int i = 0 ; i < word.length() ; i++){
        temp = temp*10 + number[(int)(word[i]-'A')];
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

    vector<char> alphabets;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < a[i].length() ; j++){
            alphabets.push_back(a[i][j]);
        }
    }
    sort(alphabets.begin(), alphabets.end());
    alphabets.erase(unique(alphabets.begin(), alphabets.end()), alphabets.end());

    int numbers[alphabets.size()];
    for(int i = 0 ; i < alphabets.size() ; i++) numbers[i] = 9 - i; // cout << alphabets[i];

    int best = 0;

    do{
        int temp = 0;
        for(int i = 0 ; i < N ; i++){
            temp = temp + get_number(numbers, a[i]);
        }
        best = max(temp, best);
    }while(prev_permutation(numbers, numbers + alphabets.size()));

    cout << best; 

    return 0;
}
