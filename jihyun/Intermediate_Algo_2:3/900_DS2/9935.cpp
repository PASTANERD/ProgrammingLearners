//9935
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string words, bomb;
    cin >> words >> bomb;
    int blen = (int)bomb.size();
    int wlen = (int)words.size();
    bool check[wlen];
    memset(check, true, wlen);
    
    if(blen == 1){
        for(int cur = 0; cur < wlen; cur++){
            if(words[cur] == bomb[0])
                check[cur] = false;
        }
    }
    else{
        stack<int> ws, bs;
        
        for(int cur = 0; cur < wlen; cur++){
                        
            //cur이 bomb의 첫문자와 일치하면 ws 스택에 넣기
            if(words[cur] == bomb[0]){
                ws.push(cur);
                bs.push(0);
            }
            
            //cur이 ws의 top과 연속되고, bs의 top과 연속되는 bomb의 문자와 일치하면 ws스택에 넣기
            else if(!ws.empty() && words[cur] == bomb[bs.top()+1]){
                ws.push(cur); bs.push(bs.top()+1);
                
                //bomb의 마지막 문자를 넣었을 때
                if(bs.top() == blen-1){
                    for(int i=0; i<blen; i++){
                        check[ws.top()] = false; ws.pop(); bs.pop();
                    }
                }
            }
            
            else{
                while(!ws.empty())
                    ws.pop();
                while(!bs.empty())
                    bs.pop();
            }
        }
    }
    
    string s = "";
    for(int i=0; i<wlen; i++){
        if(check[i])
            s += words[i];
    }
    
    if(s.size()==0)
        cout << "FRULA";
    else
        cout << s;
    
}


