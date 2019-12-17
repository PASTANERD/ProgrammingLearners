#include<iostream>
#include<string>

using namespace std;

string IsVaild(string str){
  
    int data=0;
    
    for(char c : str)
    {
        if(c=='(')
            data++;
        else
            data--;
        if(data<0)
            return "NO";
    }
    
    if(data==0)
        return "YES";
    else
        return "NO";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int data_num;
    cin >> data_num;
    cin.ignore();
    
    while(data_num--){
        string str;
        getline(cin, str);
        cout << IsVaild(str) << "\n";
    }
}

