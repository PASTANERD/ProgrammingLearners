
#include <string>
#include <vector>

using namespace std;

string compress(string s, int k){
    string answer = "";
    int rep = 1, index = 0;
    string cur = "", last = "";
    
    for(int i=0; i<s.size()/k; i++){
        cur = s.substr(index,k);
        //이전꺼와 같으면
        if(cur.compare(last)==0)
            rep++;
        //같지 않으면 last 앞에 rep 붙여서 answer에 append
        else{
            if(rep!=1)
                answer += to_string(rep);
            answer += last;
            rep = 1;
        }
        index += k;
        last = cur;
    }
    
    if(rep!=1)
        answer += to_string(rep);
    answer += last;

    //남은거 붙이기
    if(s.size()%k!=0)
        answer += s.substr(index);
    
    return answer;
}

int solution(string s) {
    int answer = s.size();
    
    //단위 : 1 ~ s의 길이/2
    int size = s.size()/2;
    for(int i=1; i<=size; i++){
        string temp = compress(s,i);
        if(answer>temp.size()) answer = temp.size();
    }
    
    return answer;
}
