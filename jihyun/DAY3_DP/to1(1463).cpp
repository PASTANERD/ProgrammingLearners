//입력 : 첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 정수 N이 주어진다.
#include <iostream>

using namespace std;

int d[1000000] = {0};

int sub(int n){
    if(n == 1)
        return 0;
    
    if(d[n] > 0)
        return d[n];
    
    int temp = sub(n-1) + 1;
    
    if(n%2 == 0)
        temp = (sub(n/2) + 1) < temp ? sub(n/2) + 1 : temp;
    
    if(n%3 == 0)
        temp = (sub(n/3) + 1) < temp ? sub(n/3) + 1 : temp;
    
    d[n] = temp;
    
    return d[n];
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    cout << sub(n);
}
//input : 첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)
//output : 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

#include <iostream>

using namespace std;

int d[1000] = {0};

int sub(int n){
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    
    if(d[n] > 0)
        return d[n];
    
    d[n] = sub(n-2) + sub(n-1);
    return d[n];
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    cout << sub(n)%10007;
}
