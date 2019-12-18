/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/11005
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

char exchange(int reserve){
    char changed_radix;
        switch(reserve){
            case 0:
                changed_radix = '0';
                break;
            case 1:
                changed_radix = '1';
                break;
            case 2:
                changed_radix = '2';
                break;
            case 3:
                changed_radix = '3';
                break;
            case 4:
                changed_radix = '4';
                break;
            case 5:
                changed_radix = '5';
                break;
            case 6:
                changed_radix = '6';
                break;
            case 7:
                changed_radix = '7';
                break;
            case 8:
                changed_radix = '8';
                break;
            case 9:
                changed_radix = '9';
                break;
            case 10:
                changed_radix = 'A';
                break;
            case 11:
                changed_radix = 'B';
                break;
            case 12:
                changed_radix = 'C';
                break;
            case 13:
                changed_radix = 'D';
                break;
            case 14:
                changed_radix = 'E';
                break;
            case 15:
                changed_radix = 'F';
                break;
            case 16:
                changed_radix = 'G';
                break;
            case 17:
                changed_radix = 'H';
                break;
            case 18:
                changed_radix = 'I';
                break;
            case 19:
                changed_radix = 'J';
                break;
            case 20:
                changed_radix = 'K';
                break;
            case 21:
                changed_radix = 'L';
                break;
            case 22:
                changed_radix = 'M';
                break;
            case 23:
                changed_radix = 'N';
                break;
            case 24:
                changed_radix = 'O';
                break;
            case 25:
                changed_radix = 'P';
                break;
            case 26:
                changed_radix = 'Q';
                break;
            case 27:
                changed_radix = 'R';
                break;
            case 28:
                changed_radix = 'S';
                break;
            case 29:
                changed_radix = 'T';
                break;
            case 30:
                changed_radix = 'U';
                break;
            case 31:
                changed_radix = 'V';
                break;
            case 32:
                changed_radix = 'W';
                break;
            case 33:
                changed_radix = 'X';
                break;
            case 34:
                changed_radix = 'Y';
                break;
            case 35:
                changed_radix = 'Z';
                break;
        }

    return changed_radix;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, B, lsb;

    cin >> N >> B;
    cin.ignore();
    
    stack<char> transradix;
    string answer;
    
    while(N > 0){
            lsb = N%B;
            N = N/B;
            transradix.push(exchange(lsb));
    }
    
    while(!transradix.empty()){
        answer.push_back(transradix.top());
        transradix.pop();
    }
    
    cout << answer << '\n';

    
}