#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    vector<int>::iterator iter;
    answer.push_back(arr.front()); 
    for(iter=arr.begin(); iter != arr.end(); iter++){
        if(answer.back() != *iter) {
            answer.push_back(*iter); 
        }
    }
    
    return answer;
}