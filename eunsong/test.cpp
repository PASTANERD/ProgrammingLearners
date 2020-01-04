#include <iostream>
#include <string>

using namespace std;

int main(){
    string vowel = "aeiou";
    string str = "qert";
    for(char x:str){
        if(vowel.find(x) == string::npos)
            cout << "자음" << endl;
        else    cout << "모음" << endl;
        
    }
    return 0;
}