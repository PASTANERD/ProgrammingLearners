#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    cin.ignore();
    
    string str;
    int data;
    stack<int> s;
    while(t--){
        cin >> str;
        if(str == "push"){
            cin >> data;
            s.push(data);
        } else if (str == "top"){
            cout << (s.empty() ? -1 : s.top()) << '\n';
        } else if (str == "size") {
            cout << s.size() << '\n';
        } else if (str == "empty"){
            cout << (s.empty() ? 1 : 0) << '\n';
        } else if (str == "pop"){
            cout << (s.empty() ? -1 : s.top()) << '\n';
            if(!s.empty()){
                s.pop();
            }
        }
        
    }
}