#include<iostream>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int size = 26;
    int alp[size];
    for(int i=0; i<size; i++){
        alp[i] = -1;
    }
    
    string s;
    cin >> s;
    
    for(int i=0; i<s.length(); i++){
        int index = s[i]-'a';
        if(alp[index] == -1)
            alp[index] = i;
    }
    
    for(int result : alp){
        cout << result << " ";
    }
}
