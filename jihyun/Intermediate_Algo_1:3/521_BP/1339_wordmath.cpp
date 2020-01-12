#include<iostream>
#include<algorithm>

using namespace std;
int sum[26] = {0,}; //각 알파벳에 해당하는 숫자

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    while(n--){
        string s;
        cin >> s;
        for(int i=1/*자릿수*/, j=s.size()-1; j>=0; i*=10,j--)
            sum[(s[j]-'A')] += i;
    }
    
    sort(sum, sum+26, greater<int>());
    
    int MAX = 0, num = 9;
    for(int i : sum){
        if(i!=0)    MAX += i*(num--);
    }
    
    cout << MAX;
}


