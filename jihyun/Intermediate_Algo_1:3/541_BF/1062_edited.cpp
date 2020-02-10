
//1062
#include <iostream>
#include <vector>

using namespace std;

int count(int mask, vector<int> &words){
    int cnt = 0;
    for(int word : words){
        //(1<<26)-1-mask : 배우지 않은 알파벳의 bitmask
        if((word&((1<<26)-1-mask)) == 0)
            cnt ++;
    }
    return cnt;
}

//index : 알파벳 index, mask : 배운 알파벳의 bitmask
int go(int index, int k, int mask, vector<int> &words){
    if(k<0) return 0;
    if(index == 26) return count(mask, words);
    int ans = 0;
    
    //index번째 알파벳 배울 경우
    int t1 = go(index+1, k-1, mask | (1<<index), words);
    if(ans < t1) ans = t1;
    
    //알파벳 아무것도 배우지 않을 경우
    if(index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'c'-'a'
       && index != 'i'-'a'){
        t1 = go(index+1, k, mask, words);
        if(ans < t1) ans = t1;
    }
    
    return ans;
        
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> words(n);   //단어를 이루고 있는 알파벳을 bitmask 형태로 저장 (a:0,b:1...)
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(char c : s)
            words[i] |= (1<<(c-'a'));
    }
    
    cout << go(0,k,0,words);
}
