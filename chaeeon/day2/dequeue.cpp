/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    string cmd;
    int data;
    deque<int> dequeue;

    for(int i = 0; i < n ; i++){
        cin >> cmd;
        if(cmd == "push_front"){
            cin >> data;
            dequeue.push_front(data);
        }
        else if(cmd == "push_back"){
            cin >> data;
            dequeue.push_back(data);
        }
        else if(cmd == "pop_front"){
            if(dequeue.empty()) cout << -1 << '\n';
            else{
                cout << dequeue.front() << '\n';
                dequeue.pop_front();
            }
        }
        else if(cmd == "pop_back"){
            if(dequeue.empty()) cout << -1 << '\n';
            else{
                cout << dequeue.back() << '\n';
                dequeue.pop_back();
            }
        }
        else if(cmd == "size") cout << (dequeue.empty() ? 0 : dequeue.size()) << '\n';
        else if(cmd == "empty") cout << (dequeue.empty() ? 1 : 0) << '\n';
        else if(cmd == "front") cout << (dequeue.empty() ? -1 : dequeue.front()) << '\n';
        else if(cmd == "back") cout << (dequeue.empty() ? -1 : dequeue.back()) << '\n';
    }
}