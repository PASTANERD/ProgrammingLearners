
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

int calculation(vector<int> ops, int* operand){
    int temp = operand[0];
    for(int i = 0 ; i < ops.size() ; i++){
        int operatorr = ops[i];
        switch(operatorr){
            case 0:
                temp += operand[i+1];
                break;
            case 1:
                temp -= operand[i+1];
                break;
            case 2:
                temp *= operand[i+1];
                break;
            case 3:
                temp /= operand[i+1];
                break;
        }
    }
    return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    int operand[N];
    int operathor[4];
    for(int i = 0 ; i < N ; i++) cin >> operand[i];
    for(int i = 0 ; i < 4 ; i++) cin >> operathor[i];

    vector<int> ops;
    for(int i = 0 ; i < 4; i++){
        /**
         * 0: + 1: - 2: * 3: /
         * */
        int temp = operathor[i];
        for(int j = 0 ; j < temp ; j++){
            ops.push_back(i);
        }
    }
    int maxo = (1 << 31);
    int mino = maxo-1;
    do{
        int result = calculation(ops, operand);
        maxo = max(maxo, result);
        mino = min(mino, result);
    }while(next_permutation(ops.begin(), ops.end()));

    cout << maxo << '\n' << mino;
    return 0;
}
