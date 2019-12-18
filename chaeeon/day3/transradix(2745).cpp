/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/2745
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <string>

using namespace std;

int exchange(char data){
    if(data == '0') return 0;
    else if(data == '1') return 1;
    else if(data == '2') return 2;
    else if(data == '3') return 3;
    else if(data == '4') return 4;
    else if(data == '5') return 5;
    else if(data == '6') return 6;
    else if(data == '7') return 7;
    else if(data == '8') return 8;
    else if(data == '9') return 9;
    else if(data == 'A') return 10;
    else if(data == 'B') return 11;
    else if(data == 'C') return 12;
    else if(data == 'D') return 13;
    else if(data == 'E') return 14;
    else if(data == 'F') return 15;
    else if(data == 'G') return 16;
    else if(data == 'H') return 17;
    else if(data == 'I') return 18;
    else if(data == 'J') return 19;
    else if(data == 'K') return 20;
    else if(data == 'L') return 21;
    else if(data == 'M') return 22;
    else if(data == 'N') return 23;
    else if(data == 'O') return 24;
    else if(data == 'P') return 25;
    else if(data == 'Q') return 26;
    else if(data == 'R') return 27;
    else if(data == 'S') return 28;
    else if(data == 'T') return 29;
    else if(data == 'U') return 30;
    else if(data == 'V') return 31;
    else if(data == 'W') return 32;
    else if(data == 'X') return 33;
    else if(data == 'Y') return 34;
    else if(data == 'Z') return 35;
    else return -1;
        
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    int B;

    cin >> N >> B;
    cin.ignore();
    
    int decimal = 0;
    for(int i = 0 ; i < N.size() ; i++){
        decimal = decimal*B + exchange(N[i]);
    }
    
    cout << decimal << '\n';

    
}