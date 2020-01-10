#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<string> words;
    int max_size = 0;
    while(n--){
        string s;
        cin >> s;
        words.push_back(s);
        max_size = max(max_size, (int)s.size());
    }
    
    vector<int> v;
    map<char,int> change;
    vector<int> num = {0,1,2,3,4,5,6,7,8,9};
    int MAX = 0;

    do{
        int cur=0;
        for(string s : words){
            for(int i=0; i<s.size(); i++){
                auto k = change.insert({s[i],num[cur]});
                if(k.second)
                    cur++;
            }
        }

        int total = 0;
        for(string s : words){
            for(int i=0, j=(int)s.size()-1; i<s.size(); i++, j--){
                total += change[s[i]]*pow(10,j);
            }
        }
        MAX = max(total, MAX);
        change.clear();
    }while(next_permutation(num.begin(), num.end()));
    
    cout << MAX;
}

//    map<char,int> change;
//    int digit = 9;
//    int cur_max = max_size;
//    int MAX = 0;
//    for(int k = 0; k < words.size(); k++){
//        while(cur_max > 0){
//            for(int i=k; i<k+words.size(); i++){
//                if(i==words.size()) i=0;
//                string s = words[i];
////            for(string s : words){//
//                if(s.size() < cur_max) continue;
//                int index = (int)s.size()-cur_max;
//                if(change.find(s[index])==change.end())
//                    change.insert({s[index],digit--});
//            }
//            cur_max--;
//        }
//
//        int total = 0;
//        for(string s : words){
//            for(int i=0, j=(int)s.size()-1; i<s.size(); i++, j--){
//                total += change[s[i]]*pow(10,j);
//            }
//        }
//        MAX = max(total, MAX);
//    }
    
//    cout << MAX;
//}

//큰 자릿수부터 채워나가면 안됨! 반례 : 2 BC AA
