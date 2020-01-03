#include <iostream>

using namespace std;

int go(int sum, int goal){
    if(sum > goal)  return 0;
    if(sum == goal) return 1;
    int count=0;
    for(int i=1; i<=3; i++){
        count += go(sum+i, goal);
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;
    int *n = new int[T];
    
    for(int i=0; i<T; i++)
        cin >> n[i];
    for(int i=0; i<T; i++){
        int count = go(0, n[i]);
        cout << count << "\n";
    }
    

    return 0;
}