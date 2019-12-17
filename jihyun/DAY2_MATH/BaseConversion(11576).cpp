#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b;
    cin >> a >> b;
    
    int size;
    cin >> size;
    
    int a_num[size];
    
    for(int i=0; i<size; i++){
        cin >> a_num[i];
    }
    
    //A to 10
    long long d_num = 0;
    
    for(int i = 0; i<size; i++){
        d_num += a_num[i] * pow(a,size-i-1);
    }
    
    //10 to B
    vector<int> b_num;
    long long q = d_num;
    while(q!=0){
        int d = q%b;
        q = q/b;
        b_num.push_back(d);
    }
    
    for(auto i = b_num.end()-1; i != b_num.begin()-1; i--){
        cout << *i << " ";
    }
}
