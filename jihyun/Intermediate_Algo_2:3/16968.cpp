

//16968
#include <iostream>
#define INIT alp=26; digit=10; repeat=0;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string type;
    cin >> type;
    int SIZE = type.size();

    int ans = 1;
    int digit = 10, alp = 26;
    char prev;
    int repeat = 0;
    
    for(int i=0; i<SIZE; i++){
        char cur = type[i];
        if(i==0 || cur!=prev){
            INIT;
            if(cur=='d') ans *= digit;
            else ans *= alp;
        }
        else{
            if(++repeat > 0){
                digit = 9;
                alp = 25;
            }
            if(cur=='d') ans *= digit;
            else ans *= alp;
        }
        prev = cur;
    }
    cout << ans;
}
