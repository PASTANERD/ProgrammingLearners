/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/11723
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>

using namespace std;

class myset{
    private:
        unsigned int set;

    public:
        myset(){
            set = 0;
        }

        void add(int i){
            set = set | (1 << i);
        }

        void remove(int i){
            set = set & ~(1 << i);
        }

        int check(int i){
            if(set & (1 << i)) return 1;
            else return 0;
        }

        void toggle(int i){
            set = set ^ (1 << i);
        }

        void all(){
            set = ~0;
        }

        void empty(){
            set = 0;
        }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;

    myset *set = new myset();

    string command;
    int number;
    for(int i = 0 ; i < M ; i++){
        cin >> command;
        if(command == "add") {
            cin >> number;
            set->add(number);
        }
        else if(command == "remove") {
            cin >> number;
            set->remove(number);
        }
        else if(command == "check") {
            cin >> number;
            cout << set->check(number) << '\n';
            }
        else if(command == "toggle") {
            cin >> number;
            set->toggle(number);
        }
        else if(command == "all") set->all();
        else if(command == "empty") set->empty();
        else cout << "not a command" << '\n';
    }

    return 0;
}
