#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int E, S, M;
    cin >> E >> S >> M;
    
    int a=1, b=1, c=1;
    int year = 1;
    
    while(a!=E || b!=S || c!=M){
        year ++;
        a = (a==15) ? 1 : a+1;
        b = (b==28) ? 1 : b+1;
        c = (c==19) ? 1 : c+1;
    }
    
    cout << year;
}
