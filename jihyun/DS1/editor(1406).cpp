#include<iostream>
#include<string>
#include<stack>

using namespace std;

stack<char> left_s;
stack<char> right_s;

void L(){
    if(left_s.empty())
        return;
    right_s.push(left_s.top());
    left_s.pop();
}

void D(){
    if(right_s.empty())
        return;
    left_s.push(right_s.top());
    right_s.pop();
}

void B(){
    if(left_s.empty())
        return;
    left_s.pop();
}

void P(char add){
    left_s.push(add);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++){
        left_s.push(str[i]);
    }
    
    int num;
    cin >> num;
    
    while(num--){
        char cmd;
        cin >> cmd;
        
        switch(cmd){
            case 'L' : L(); break;
            case 'D' : D(); break;
            case 'B' : B(); break;
            default: char add;
                cin >> add;
                P(add); break;
        }
    }
    
    while(!left_s.empty()){
        right_s.push(left_s.top());
        left_s.pop();
    }
    
    while(!right_s.empty()){
        cout << right_s.top();
        right_s.pop();
    }
}


