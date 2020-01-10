#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int k;
vector<char> sign;

bool satisfied(vector<int> v){
    for(int i=0; i<k; i++){
        switch(sign[i]){
            case '>' : if(v[i]<v[i+1]) return false; break;
            case '<' : if(v[i]>v[i+1]) return false; break;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> k;
    
    for(int i=0; i<k; i++){
        char c;
        cin >> c;
        sign.push_back(c);
    }
    
    vector<int> MIN;
    vector<int> MAX;
    for(int i=0; i<=k; i++){
        MIN.push_back(i);
        MAX.push_back(9-i);
    }
    
    do{
        if(satisfied(MAX))
            break;
    }while(prev_permutation(MAX.begin(), MAX.end()));
    
    do{
        if(satisfied(MIN))
            break;
    }while(next_permutation(MIN.begin(), MIN.end()));
    
    for(int i : MAX)
        cout << i;
    cout << endl;
    for(int i : MIN)
        cout << i;
}

