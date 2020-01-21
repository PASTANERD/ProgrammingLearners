#include<iostream>

using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    
    int n_2 = n/2;
    int team = min(n_2, m);
    int remain = n + m - team * 3;
    
    int t = k - remain;
    
    if(t <= 0)
        cout << team;
    else
        cout << team - ((t-1)/3 + 1);
}
