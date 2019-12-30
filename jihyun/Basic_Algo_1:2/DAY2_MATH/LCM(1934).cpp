#include <iostream>

using namespace std;

int GCD(int a, int b){
    if(b==0)
        return a;
    else
        return GCD(b, a%b);
}

int LCM(int a, int b){
    return (a*b)/(GCD(a,b));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int num;
    cin >> num;
    
    while(num--){
        int a, b;
        cin >> a >> b;
        cout << LCM(a,b) << '\n';
    }
}
