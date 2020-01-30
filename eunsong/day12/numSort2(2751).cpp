#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    int *num = new int[n];
    fill_n(num, 0, n);

    for(int i=0; i<n; i++)
        cin >> num[i];

    sort(num, num+n);
    
    for(int i=0; i<n; i++)
        cout << num[i] << "\n";

    return 0;
}