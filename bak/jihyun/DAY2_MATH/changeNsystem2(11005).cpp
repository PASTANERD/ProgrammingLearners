#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, b;
    cin >> n >> b;
    
    stack<string> s;
    long long q = n;
    
    while(q!=0){
        long long d = q%b;
        q = q/b;
        string in;
        
        if(d<10)
            in = to_string(d);
        else
            in = 'A' + (d-10);
        
        s.push(in);
    }
    
    long long size = s.size();
    
    while(size--){
        cout << s.top();
        s.pop();
    }
}
