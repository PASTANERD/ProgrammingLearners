#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

vector<char> digit = {'0','1','2','3','4','5','6','7','8','9'};

bool check(string s){
    
    for(int i=0; i<s.size(); i++){
        if(find(digit.begin(), digit.end(), s[i]) == digit.end())
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    string ch = to_string(n);
    int size = ch.size();

    if(n==100){
        cout << '0';
        return 0;
    }
    
    int answer = abs(100 - n);
    
    if(m == 10){
        cout << answer;
        return 0;
    }
    
    for(int i=0; i<m; i++){
        char temp;
        cin >> temp;
        auto w = find(digit.begin(), digit.end(), temp);
        digit.erase(w);
    }
   
    for(int i=0; i<1000000; i++){
        string s = to_string(i);
        if(check(s)){
            int put = s.size();
            put += abs(n-i);
            if(put < answer)
                answer = put;
        }
    }
    
    cout << answer;
}
