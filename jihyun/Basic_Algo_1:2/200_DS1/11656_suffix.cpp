#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string s;
    cin >> s;
    
    vector<string> suffix;
    int size = s.size();
    
    for(int i=0; i<size; i++){
        suffix.push_back(s.substr(i));
    }

    sort(suffix.begin(), suffix.end());
    
    for(string s : suffix){
        cout << s << '\n';
    }
}
