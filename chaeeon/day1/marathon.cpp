/*
*   Programmers.co.kr Coding Test Practice
*   https://programmers.co.kr/learn/challenges
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    vector<string> athletes = participant;
    
    for(vector<string>::iterator itr = completion.begin() ; itr != completion.end() ; itr++){
        for(vector<string>::iterator ptr = athletes.begin() ; ptr != athletes.end() ; ptr++){
            if(*itr== *ptr) {
                athletes.erase(ptr);
                break;
            }
        }
    }    
    answer = athletes.front();
    return answer;
}