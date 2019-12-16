#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int data_num=0;
    cin >> data_num;
    cin.ignore();
    
    while(data_num--){
        string stm;
        stack<char> c;
        getline(cin,stm);
        stm += '\n';

        for(char ch : stm){
            if(ch==' ' || ch=='\n')
            {
                while(!c.empty()){
                    cout << c.top();
                    c.pop();
                }
                cout << " ";
            }
            else{
                c.push(ch);}
        }
    }
}
