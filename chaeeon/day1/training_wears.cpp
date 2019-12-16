#include <string>
#include <vector>

using namespace std;
class Student{
    public:
    int have;
    Student* next;
    Student* previous;
};

class LinkedList{
  public:
    Student* firstStudent;
    Student* curStudent;
    int size;
    
    LinkedList(){
        firstStudent = NULL;
        curStudent = NULL;
        size = 0;
    }
    
    void addStudent(int number){
        Student* student = new Student();
        
        student->have = number;
        student->previous = curStudent;
        
        curStudent = student;
        if(student->previous != NULL) student->previous->next = curStudent;
        else firstStudent = student;
        size++;
    }
    
    Student* getStudent(int index){
        Student* targetStudent = firstStudent;
        for(int i = 0; i < index-1 ; i++){
            targetStudent = targetStudent->next;
        }
        return targetStudent;
    }
};

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    LinkedList* StudentList = new LinkedList();
    Student* student;
    
    // make student list
    for(int i = 0; i < n; i++){
        StudentList->addStudent(1);
    }
    
    // subtract lost
    for(vector<int>::iterator itr = lost.begin(); itr != lost.end(); itr++){
        student = StudentList->getStudent(*itr);
        student->have -= 1;
    }
    
    // add reserve
    for(vector<int>::iterator itr = reserve.begin(); itr != reserve.end(); itr++){
        student = StudentList->getStudent(*itr);
        student->have +=1;
    }
    
    // borrow
    student = StudentList->firstStudent;
    for(int i = 0; i < n; i++){
        if(student->have == 0){
            // borrow from next student
            if(student->next != NULL){
                if(student->next->have > 1){
                    student->have += 1;
                    student->next->have -= 1;
                }
            }
            // borrow from previous student if next student have nothing
            if(student->previous != NULL && student->have == 0){
                if(student->previous->have > 1){
                    student->have += 1;
                    student->previous->have -= 1;
                }
            }
        }
        student = student->next;
    }
    
    student = StudentList->firstStudent;
    for(int i = 0; i < n; i++){
        if(student->have>0) answer++;
        student = student->next;   
    }
    return answer;
}