// 1747
// N (1 ≤ N ≤ 1,000,000)
// N보다 크거나 같고, 소수이면서 팰린드롬인 수 중에서, 가장 작은 수를 구하는 프로그램

#include <vector>
#include <iostream>

using namespace std;

/* 펠린드롬 */
bool is_pel(int n){
    //자릿수 검사
    int digit_num = 0, temp = n;
    vector<int> digit;
    
    while(temp>0){
        digit.push_back(temp%10);
        temp /= 10;
        digit_num ++;
    }

    for(int i=0; i<digit_num/2; i++){
        if(digit[i]!=digit[digit_num-1-i])
            return false;
    }
    return true;
}

bool is_prime(int n){
    if(n==1)
        return false;
    
    for(int i=3; i<n; i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    
    int x = n;
    
    if(n==1 || n==2){
        cout << 2 << '\n';
        exit(0);
    }
    
    if(x%2 == 0)
        x++;
    
    while(1){
        if(is_pel(x)){
            if(is_prime(x)){
                break;
            }
        }
        x+=2;
    }
    
    cout << x << '\n';
}

