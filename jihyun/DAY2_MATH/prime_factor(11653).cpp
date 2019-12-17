#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    cin >> n;
    
    //n이하의 소수 찾기
    vector<int> prime;
    bool check[n+1];
    fill_n(check, n+1, false);
    for(int i = 2; i <= n; i++){
        if(!check[i]){
            prime.push_back(i);
            for(long long j = i+i; j <= n; j*=i)
                check[j] = true;
        }
    }
    
    long long q = n;
    int i = 0;
    
    while(q!=1){
        int p = prime[i];
        if(q % p == 0){
            cout << p << '\n';
            q /= p;
        }
        else
            i++;
    }
}
