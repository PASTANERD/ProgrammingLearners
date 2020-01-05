#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    int N;
    int S;

    cin >> N >> S;  

    int *A = new int[N];
    for(int i = 0; i < N; i++)
        cin >> A[i]; 
    
    vector<int> D(N);
    for(int i = 0; i < N; i++){
        D[i] = max(S, A[i]) - min(S, A[i]);
    }

    cout << *min_element(D.begin(), D.end()) << endl;

    return 0;
}