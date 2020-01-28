
//10815
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    int* cards;
    cin >> n;
    cards = new int[n];
    for(int i=0; i<n; i++){
        cin >> cards[i];
    }
    sort(cards, cards+n);
    
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
                has = 1;
                break;
            }
            else if(num < cards[mid])
                right = mid-1;
            else
                left = mid+1;
        }
        cout << has << ' ';
    }
}



