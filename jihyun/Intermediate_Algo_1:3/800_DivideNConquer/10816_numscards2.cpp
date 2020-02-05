//10816
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    vector<int> cards;
    cin >> n;
    map<int,int> cnt;
    
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(find(cards.begin(), cards.end(), tmp)==cards.end()){
            cards.push_back(tmp);
            cnt.insert({tmp,1});
        }
        else{
            cnt[tmp]++;
        }
    }
    
    sort(cards.begin(), cards.end());
    
    cin >> m;
    
    while(m--){
        int num;
        cin >> num;
        int left = 0;
        int right = n-1;
        int has = 0;
        while(left <= right){
            int mid = (left+right)/2;
            if(num == cards[mid]){
                has = cnt[num]; break;
            }
            else if(num < cards[mid])
                right = mid-1;
            else
                left = mid+1;
        }
        cout << has << ' ';
    }
}




