
/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/16198
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 구슬 N개가 주어지면,
 * 2번째부터 N-1개 사이 중 x번째 구슬 선택하여 제거 (3 <= N <= 10)
 * Wx-1 x Wx+1 의 에너지를 모은다.
 * 구슬의 개수가 2개가 될때까지 구하는 것을 여러 번 반복할 때, 에너지가 최대가 되는 값
 * 
*/

int N;
vector<int> marbles;

int get_energy(int sum, vector<int> list){
    if(list.size() == 2) return sum;

    int best = 0, buffer;
    for(int i = 1 ; i < list.size()-1 ; i++){
        int temp = list[i];
        int energy = list[i-1]*list[i+1];

        list.erase(list.begin()+i);
        buffer = get_energy(sum+energy, list);
        list.insert(list.begin()+i, temp);

        if(buffer > best) best = buffer;
    }
    return best;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;

    for(int i = 0 ; i < N ; i++){
        int temp = 0;
        cin >> temp;
        marbles.push_back(temp);
    }


    int answer = 0;
    for(int i = 1 ; i < N-1 ; i++){
        int backup = marbles[i];
        int energy = marbles[i-1]*marbles[i+1];

        marbles.erase(marbles.begin() + i);
        int temp = get_energy(0+energy, marbles);
        marbles.insert(marbles.begin() + i , backup);
        
        if(answer < temp) answer = temp;
    }
    

    cout << answer;

    return 0;
}