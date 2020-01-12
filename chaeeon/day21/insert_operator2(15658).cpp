
/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/15658
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

long long calculation(vector<int> ops, int* operand){
    long long temp = operand[0];
    for(int i = 0 ; i < N-1 ; i++){
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
    long long  operathor[4];
    for(int i = 0 ; i < N ; i++) cin >> operand[i];
    for(int i = 0 ; i < 4 ; i++) cin >> operathor[i];

    vector<int> ops;
    /**
     * 0: + 1: - 2: * 3: /
    * */
    for(int i = 0 ; i < 4; i++) ops.insert(ops.end(), operathor[i], i);
        
    long long mino = (long long) ((~((unsigned long long) 0)) >> 1); 
    long long maxo = mino + 1;

    do{
        long long result = calculation(ops, operand);
        maxo = max(maxo, result);
        mino = min(mino, result);
    }while(next_permutation(ops.begin(), ops.end()));

    cout << maxo << '\n' << mino;
    return 0;
}
