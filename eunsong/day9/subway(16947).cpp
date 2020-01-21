#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> arr[3000];
bool check[3000][3000] = {false};

bool findCircle(int v, vector<int> &circle){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    int from, to;
    for(int i=0; i<n; i++){
        cin >> from >> to;
        arr[from].push_back(to);
    }

    vector<int> circle;
    bool ans = findCircular(1, circle);''

    return 0;
}