#include <iostream>

using namespace std;

enum Options{Add,Remove,Check,Toggle,All,Empty,Default};

Options resolveOption(string input){
    if(input == "add") return Add;
    else if(input == "remove") return Remove;
    else if(input == "check") return Check;
    else if(input == "toggle") return Toggle;
    else if(input == "all") return All;
    else if(input == "empty") return Empty;
    return Default;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    
    string input; 
    int x;
    unsigned int num = 0;
    for(int i=0; i<n; i++){        
        cin >> input;
        switch(resolveOption(input)){
            case Add: cin >> x; num = num | (1 << x); break;
            case Remove:  cin >> x; num = num & ~(1 << x); break;
            case Check: { cin >> x;
                        if(num & (1 << x)) cout << 1 << "\n"; 
                        else cout << 0 << "\n"; break;}
            case Toggle:  cin >> x; num = num ^ (1 << x); break;
            case All:  num = ~0; break;
            case Empty:  cin >> x; num = 0; break;
            case Default: break;
            default: break;
        }
    }

    return 0;
}