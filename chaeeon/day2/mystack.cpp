/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack{
    private:
    int cap;
    int *stack;
    
    public:
    Stack(){
        cap = 0;
        stack = (int*)malloc(sizeof(int)*100000);
    }
    Stack(int stack_size){
        cap = 0;
        stack = (int*)malloc(sizeof(int)*stack_size);
    }
    
    void push(int data){
        stack[cap] = data;
        cap += 1;
    }
    
    int pop(){
        if(empty()) return -1;
        else{
            int temp = stack[cap-1];
            stack[cap-1] = 0;
            cap -= 1;
            return temp;
        }
    }
    
    int top(){
        if(empty()) return -1;
        else return stack[cap-1];
    }
    
    int size(){
        return cap;
    }
    
    int empty(){
        if(cap == 0) return true;
        else return false;
    }
    
    ~Stack(){
        free(stack);
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int data;
    string s;
    string cmd;

    cin >> n;
    cin.ignore();
    Stack* stack = new Stack();
    
    for(int i = 0; i < n; i++){
        cin >> cmd;
        if(cmd.compare("push")==0){
            cin >> data;
            stack->push(data);
        }
        else if(cmd.compare("pop")==0) cout << stack->pop() << '\n';
        else if(cmd.compare("top")==0) cout << stack->top() << '\n';
        else if(cmd.compare("size")==0) cout << stack->size() << '\n';        
        else if(cmd.compare("empty")==0) cout << stack->empty() << '\n';        
    }
    
    
    delete stack;

    return 0;
}
