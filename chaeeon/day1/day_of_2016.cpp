#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int i = 0;  // 31 days in a month
    int j = 0;  // 30 days in a month
    int feb = 0;
    switch(a){
        case 1:
            break;
        case 2:
            i = 1;
            break;
        case 3:
            i = 1;
            feb = 1;
            break;
        case 4:
            i = 2;
            feb = 1;
            break;
        case 5:
            i = 2;
            j = 1;
            feb = 1;
            break;
        case 6:
            i = 3;
            j = 1;
            feb = 1;
            break;
        case 7:
            i = 3;
            j = 2;
            feb = 1;
            break;
        case 8:
            i = 4;
            j = 2;
            feb = 1;
            break;
        case 9:
            i = 5;
            j = 2;
            feb = 1;
            break;
        case 10:
            i = 5;
            j = 3;
            feb = 1;
            break;
        case 11:
            i = 6;
            j = 3;
            feb = 1;
            break;
        case 12:
            i = 6;
            j = 4;
            feb = 1;
            break;
    }
    
    int count = 31 * i + 30 * j + 29 * feb + b;
    // 62 60 29 24 = 122 53 175 / 7 = 25
    int date = count % 7;
    
    switch(date){
        case 1:
            answer = "FRI";
            break;
        case 2:
            answer = "SAT";
            break;
        case 3:
            answer = "SUN";
            break;
        case 4:
            answer = "MON";
            break;
        case 5:
            answer = "TUE";
            break;
        case 6:
            answer = "WED";
            break;
        case 0:
            answer = "THU";
            break;
    }
    return answer;
}