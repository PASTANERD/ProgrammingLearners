#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string cmd;
    int data;
    
    cin >> n;
    cin.ignore();
    queue<int> queue;
    for(int i = 0 ; i < n ; i++){
        cin >> cmd;
        if(cmd == "push"){
            cin >> data;
            queue.push(data);
        }
        else if(cmd == "pop"){
            if(queue.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << queue.front() << '\n';
                queue.pop();
            }
        }
        else if(cmd == "size") cout <<  queue.size() << '\n';
        else if(cmd == "empty") cout << queue.empty() << '\n';
        else if(cmd == "front") cout << (queue.empty() ? -1 : queue.front()) << '\n';
        else if(cmd == "back") cout << (queue.empty() ? -1 : queue.back()) << '\n';
    }
}