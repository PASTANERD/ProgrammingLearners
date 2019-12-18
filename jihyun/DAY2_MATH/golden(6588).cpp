#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    bool check[MAX+1];
    vector<int> prime;
    
    fill_n(check, MAX+1, false);
    
    for(int i = 2; i <= MAX; i++){
        if(!check[i]){
            prime.push_back(i);
            for(int j = i+i; j<=MAX; j+=i){
                check[j] = true;
            }
        }
    }
    
    int size = prime.size();
    
    while(true){
        int n;
        cin >> n;
        
        if(n==0)
            break;
        
        for(int i = 1; i < size; i++){
            if(!check[n-prime[i]]){
                cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
                break;
            }
        }
    }
}
