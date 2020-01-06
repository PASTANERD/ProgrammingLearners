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

int student1(vector<int> answers){
    int count = 0;
    int index = 0;
    int cheat[5] = {1,2,3,4,5};
    for(vector<int>::iterator itr = answers.begin(); itr != answers.end() ;itr++){
        if(index>=5) index = 0;
        if(*itr == cheat[index]) count++;
        index++;
    }
    
    return count;
}

int student2(vector<int> answers){
    int count = 0;
    int index = 0;
    int cheat[8] = {2,1,2,3,2,4,2,5};
    for(vector<int>::iterator itr = answers.begin(); itr != answers.end() ;itr++){
        if(index>=8) index = 0;
        if(*itr == cheat[index]) count++;
        index++;
    }
    
    return count;
}

int student3(vector<int> answers){
     int count = 0;
    int index = 0;
    int cheat[10] = {3,3,1,1,2,2,4,4,5,5};
    for(vector<int>::iterator itr = answers.begin(); itr != answers.end() ;itr++){
        if(index>=10) index = 0;
        if(*itr == cheat[index]) count++;
        index++;
    }
    
    return count;
}

int comparing(int a, int b){
    if(a > b) return 1;
    if(a < b) return -1;
    else return 0;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int score1 = student1(answers);
    int score2 = student2(answers);
    int score3 = student3(answers);
    
    int compares12 = comparing(score1, score2);
    int compares13 = comparing(score1, score3);
    int compares23 = comparing(score2, score3);
     /*
     1   1>2, 1>3, 2?3 
     13  1>2, 1=3, 2<3
     3   1?2, 1<3, 2<3
     */
    if(compares12 > 0){
        answer.push_back(1);
        if(compares13 == 0) answer.push_back(3);
        else if(compares13 < 0){
            answer.pop_back();
            answer.push_back(3);
        }
    }
    /*
     2   1<2, 1?3, 2>3
     23  1<2, 1<3, 2=3
     3   1?2, 1<3, 2<3
     */
    else if(compares12 < 0){
        answer.push_back(2);
        if(compares13 < 0){
            if(compares23 == 0) answer.push_back(3);
            else if(compares23 < 0){
                answer.pop_back();
                answer.push_back(3);
            }
        }
    }
    
    /*
     12  1=2, 1>3, 2>3
     123 1=2, 1=3, 2=3
     3   1?2, 1<3, 2<3
     */
    else{
        answer.push_back(1);
        if(compares13>0)answer.push_back(2);
        else if(compares13<0){
            answer.pop_back();
            answer.push_back(3);
        }
        else {
            answer.push_back(2);
            answer.push_back(3);
        }
    }
    
    return answer;
}