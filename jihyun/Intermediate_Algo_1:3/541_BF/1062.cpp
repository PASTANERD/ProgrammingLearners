//1062
#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<char> alp;
map<char,bool> status;
char must[] = {'a','c','i','n','t'};
int n, k;

void init(){
    for(auto a : alp)
        status[a] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    
    if(k < 5){
        cout << 0;
        return 0;
    }
    
    string words[n];

    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        words[i] = "";
        for(char t : temp){
            if(t!='a' && t!='i' && t!='c' && t!='n' && t!='t'){
                words[i] += t;
                status.insert({t,false});
            }
        }
    }
    
    for(auto i : status)
        alp.push_back(i.first);
    
    int SIZE = (int)alp.size();
    k -= 5;
    int MAX = 0;
    
    for(int i=0; i<(1<<SIZE); i++){
        init();
        int sum = 0, num = 0;
        
        for(int j=0; j<SIZE; j++){
            if(num > k) break;
            if(i&(1<<j)){
                num++;
                status[alp[j]] = true;
            }
        }
        if((k > SIZE && num != SIZE) || (k <= SIZE && num != k)) continue;
        
        for(string s : words){
           bool possible = true;
           for(char t : s){
               if(!status[t]){
                   possible = false; break;
               }
           }
           if(possible) sum++;
        }
        MAX = max(MAX, sum);
    }
    
    cout << MAX;
}
