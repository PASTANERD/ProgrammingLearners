//11723 Union

#include<iostream>

using namespace std;

int s = 0;
void add(int x){
    s = s|(1<<(x-1));
}

void remove(int x){
    s = s&~(1<<(x-1));
}

int check(int x){
    if(s&(1<<(x-1)))
        return 1;
    return 0;
}

void toggle(int x){
    s = s^(1<<(x-1));
}

void all(){
    s = (1<<20)-1;
}

void empty(){
    s = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int size;
    cin >> size;
    
    while(size--){
        string cmd;
        cin >> cmd;
        
        if(cmd == "all"){
            all(); continue;}
        if(cmd == "empty"){
            empty(); continue;}
        
        int x;
        cin >> x;
    
        if(cmd == "add")
            add(x);
        else if(cmd == "remove")
            remove(x);
        else if(cmd == "check")
            cout << check(x) << '\n';
        else
            toggle(x);
    }
}
