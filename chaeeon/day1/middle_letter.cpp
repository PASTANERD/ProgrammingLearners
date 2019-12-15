#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.length();
    int divider = len%2;
    int cursor = len / 2;
    switch(divider){
        case 0:
            answer = s.substr(cursor-1,2);
            break;
        case 1:
            answer = s.at(cursor);
            break;
        default:
            break;
    }
    return answer;
}