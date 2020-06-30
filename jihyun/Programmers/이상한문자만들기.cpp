#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int index = 0;
    for(int i=0; i<s.size(); i++, index++){
        if(s[i] == ' '){
            answer += " ";
            index = -1; continue;
        }
        
        answer += (index%2!=0) ? tolower(s[i]) : toupper(s[i]);
        // if(index%2!=0)
        //     answer += tolower(s[i]);
        // else
        //     answer += toupper(s[i]);
    }
    
    return answer;
}
