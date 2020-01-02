#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int k;
    cin >> k;

    vector<int> s(k);
    vector<int> a(k);
    for(int i=0; i<k; i++){
        cin >> s[i];
        if(i < 6) a[i] = 1;
    }
    for(int i=6; i<k; i++)
        a[i] = 0;
   

    do{
        for(int i=0; i< k; i++){
            if(a[i])    cout << s[i] << " ";
        } 
        cout << endl;
    }while(prev_permutation(a.begin(), a.end()));

    return 0;
}