//1759
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool check(string pw){
    int vw = 0;
    
    for(char c : pw)
        if(c=='a' || c=='e' || c=='o' || c=='i' || c=='u')
            vw++;
    int cs = pw.size()-vw;
    
    return (vw>=1 && cs>=2);
}

void find_password(int n, vector<char> alp, string pw, int index){
    
    if(pw.size() == n){
        if(check(pw))
            cout << pw << '\n';
        return;
    }
    
    if(index >= alp.size())
        return;
    
    find_password(n, alp, pw+alp[index], index+1);
    find_password(n, alp, pw, index+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int l, c;
    cin >> l >> c;
    
    vector<char> v;
    for(int i=0; i<c; i++){
        char temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(),v.end());
    find_password(l, v, "", 0);
}
