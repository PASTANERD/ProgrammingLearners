/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/17103
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/


#include <iostream>
#include <vector>
#define MAX_ARRAY 1000000

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> primes;
    bool check[MAX_ARRAY+1];

    fill_n(check, MAX_ARRAY+1, true);

    for(int i = 2 ; i <= MAX_ARRAY ; i++ ){
        if(check[i]){
            for(int j = i+1 ; j <= MAX_ARRAY ; j++) if(j%i == 0) check[j] = false;
            primes.push_back(i);
        }
    }

    int T;
    cin >> T;
    
    int N;
    int count = 0;
    for(int i = 0 ; i < T ; i++){
        cin >> N;
        for(vector<int>::iterator itr = primes.begin() ; *itr <= N/2; itr++){
            if(check[N-(*itr)]) count++;
        }
        
        cout << count << '\n';
        count = 0;
    }


    return 0;
}