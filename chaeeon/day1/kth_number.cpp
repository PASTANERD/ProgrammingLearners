#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> crop(vector<int> array, int i, int j){
    vector<int> container;
        
    for(vector<int>::iterator iter = array.begin() + i - 1; iter != array.begin() + j; iter++){
        container.push_back(*iter);
    }
    return container;
}

int kth_number(vector<int> array, vector<int> command){
    int i = command.at(0);
    int j = command.at(1);
    int k = command.at(2);
    
    vector<int> cropped = crop(array, i, j);
    sort(cropped.begin(), cropped.end());
    
    return cropped.at(k-1);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands){
    vector<int> answer;
    
    for(vector<vector<int>>::iterator command = commands.begin() ; command != commands.end(); command++){
        answer.push_back(kth_number(array, *command));
    }
    
    return answer;
}