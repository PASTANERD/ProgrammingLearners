#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int answer = 1;
    
    for(int i = n; i>1; i--){
        answer *= i;
    }
    
    cout << answer;
}

