#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, c;
    cin >> a >> b >> c;
    
    cout << (a+b)%c << '\n' << (a%c+b%c)%c << '\n' << (a*b)%c << '\n' << (a%c * b%c)%c;
}
