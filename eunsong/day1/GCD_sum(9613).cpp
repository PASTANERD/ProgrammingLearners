#include <iostream>
#include <array>

using namespace std;

const int MAX = 100;
int arr[MAX];

int GCDSum(int a, int b){
    if(b == 0)
        return a;
    else{
        return GCDSum(b, a%b);
    }
}

int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        int n;
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> arr[i];

        long sum = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i+1; j < n; j++){
                sum += GCDSum(arr[i], arr[j]);
            }
        }
        cout << sum << endl;
    }
    
    return 0;
}