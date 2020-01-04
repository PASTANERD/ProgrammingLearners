#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string vowel = "aeiou";
bool check(const string& password){
    int mo=0, ja=0;
    for(char x : password){
        if(vowel.find(x) == string::npos)
            ja++;
        else    mo++;
    }
    if(mo >= 1 && ja >= 2)
        return true;
    return false;
}
void go(int n, const vector<char> &alpha, int i, string password){
     if(password.length() == n){
         if(check(password)){
             cout << password << "\n";
         }
         return;
     }
     if(i >= alpha.size()) return;
     go(n, alpha, i+1, password+alpha[i]);
     go(n, alpha, i+1, password);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int L, C;
    cin >> L >> C;
    vector<char> alpha(C);
    for(int i=0; i<C; i++)
        cin >> alpha[i];
    sort(alpha.begin(), alpha.end());
    go(L, alpha, 0, "");

    return 0;
}