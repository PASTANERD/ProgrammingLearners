//9095
#include<iostream>

using namespace std;

int go(int sum, int goal){
    if(sum > goal)
        return 0;
    
    if(sum == goal)
        return 1;
    
    int ans = 0;
    for(int i=1; i<=3; i++)
        ans += go(sum+i,goal);
    
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int size;
    cin >> size;
    
    while(size--){
        int num;
        cin >> num;
        cout << go(0,num) << '\n';
    }
    
}
