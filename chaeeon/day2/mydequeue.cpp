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
#define DEFAULT_SIZE 10000

using namespace std;
class Deque{
    private:
    int cap;
    int array_size;
    int front_pointer;
    int back_pointer;
    int* deque_array;
    public:
    Deque(int deque_size_income = DEFAULT_SIZE){
        array_size = deque_size_income;
        cap = 0;
        front_pointer = 0;
        back_pointer = front_pointer + 1;
        deque_array = (int*)malloc(sizeof(int)*array_size);
    }

    void push_front(int data){
        cap++;
        deque_array[front_pointer] = data;
        back_pointer--;
        if(front_pointer < 0) front_pointer = array_size - 1;
    }

    void push_back(int data){
        cap++;
        deque_array[back_pointer] = data;
        back_pointer++;
        if(back_pointer == array_size) back_pointer = 0;
    }

    int pop_front(){
        cap--;
    }

    int pop_back(){

    }

    int size(){

    }

    int empty(){

    }
    
    int front(){

    }

    int back(){

    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    string cmd;
    int data;
    Deque* dequeue = new Deque();

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