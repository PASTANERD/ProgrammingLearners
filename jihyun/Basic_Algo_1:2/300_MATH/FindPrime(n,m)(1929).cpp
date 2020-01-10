#include <iostream>
#include <vector>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int min, max;
    cin >> min >> max;

    bool check[max+1];  //지워진 여부
    vector<int> prime;
    
    fill_n(check, max+1, false);
    
    for(int i = 2; i <= max; i++){
        if(!check[i]){
            if(i>=min)
                prime.push_back(i);
            for(int j = i+i; j<= max; j+=i){
                check[j] = true;
            }
        }
    }
    
    for(int i : prime){
        cout << i <<'\n';
    }
}
