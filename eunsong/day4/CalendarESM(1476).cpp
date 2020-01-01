#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int E,S,M;
    cin >> E >> S >> M;

    int year = 1, e=1, s=1, m=1;
    while(e!=E || s!=S || m!=M){
        e = (e==15) ? 1 : e+1;
        s = (s==28) ? 1 : s+1;
        m = (m==19) ? 1 : m+1;
        year++;
    }

    cout << year << "\n";
    return 0;
}