#include <iostream>
#include <string>
#define DEFAULT_SIZE 100000
using namespace std;

class Queue{
    private:
    int cap;
    int front_pointer;
    int back_pointer;
    int queue_size;
    int *queue_array;
    public:
    Queue(int queue_size_income = DEFAULT_SIZE){
        queue_size = queue_size_income;
        cap = 0;
        front_pointer = 0;
        back_pointer = 0;
        queue_array = (int*)malloc(sizeof(int)*queue_size);
    }
    ~Queue(){
        free(queue_array);
    }

    void push(int data){
        cap++;
        queue_array[back_pointer] = data;
        back_pointer +=1;
        if(back_pointer == queue_size) back_pointer = 0;
    }

    int pop(){
        if(empty()) return -1;
        else{
            cap--;
            int temp = queue_array[front_pointer];
            queue_array[front_pointer] = 0;
            front_pointer += 1;
            if(front_pointer == queue_size) front_pointer = 0;
            return temp;
        }
    }

    int size(){
        return cap;
    }
    
    int empty(){
        if(cap==0) return true;
        else return false;
    }

    int front(){
        if(empty()) return -1;
        else return queue_array[front_pointer];
    }

    int back(){
        if(empty()) return -1;
        else return queue_array[back_pointer-1];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string cmd;
    int data;
    
    cin >> n;
    cin.ignore();
    Queue *queue = new Queue();
    for(int i = 0 ; i < n ; i++){
        cin >> cmd;
        if(cmd == "push"){
            cin >> data;
            queue->push(data);
        }
        else if(cmd == "pop"){
            cout << queue->pop() << '\n';
        }
        else if(cmd == "size") cout <<  queue->size() << '\n';
        else if(cmd == "empty") cout << queue->empty() << '\n';
        else if(cmd == "front") cout << queue->front() << '\n';
        else if(cmd == "back") cout <<  queue->back() << '\n';
    }
}