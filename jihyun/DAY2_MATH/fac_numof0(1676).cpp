#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int answer = 0;
    
    for(int i = 5; i < n; i*=5)
        answer += n/i;
    
    cout << answer;
}

