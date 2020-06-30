#include <iostream>
#include <string>
using namespace std;

int max_len(string s, int center){
    int max = 1;
    
    //홀수 경우
    int temp = 1;
    for(int i=1; center+i < s.size() && center-i >= 0; i++){
        if(s[center+i] != s[center-i]) break;
        temp += 2;
    }
    if(max < temp) max = temp;
    
    //짝수 경우 (왼쪽이랑 같은 경우)
    if(s[center-1] == s[center]){
        temp = 2;
        for(int i=1; center+i < s.size() && center-i-1 >= 0; i++){
               if(s[center+i] != s[center-i-1]) break;
               temp += 2;
           }
        if(max < temp) max = temp;
    }
   
    //짝수 경우 (오른쪽이랑 같은 경우)
    if(center+1 < s.size() && s[center+1] == s[center]){
       temp = 2;
       for(int i=1; center+i+1 < s.size() && center-i >= 0; i++){
              if(s[center+i+1] != s[center-i-1]) break;
              temp += 2;
          }
       if(max < temp) max = temp;
   }
    
    return max;
}

int solution(string s) {
    int answer = 1;
    
    //팰린드롬의 중심을 정하고 해당 팰린드롬의 가장 긴 길이 구하기
    for(int i=1; i<s.size()-1; i++){
        int temp = max_len(s,i);
        if(answer < temp) answer = temp;
    }
    
    return answer;
}
