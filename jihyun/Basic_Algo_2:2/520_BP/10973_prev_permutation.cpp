//10973 previous permutation

#include<iostream>
#include<vector>

using namespace std;

bool prev_permutation(vector<int>& v){
    
    int size = v.size();
    int i = size - 1;
    while(i > 0 && v[i-1] <= v[i])
        i--;
    
    if(i <= 0)
        return false;
    
    int j = size - 1;
    while(v[j] >= v[i-1])
        j--;
    
    swap(v[j], v[i-1]);
    
    for(int k = i, l = size - 1; k < l; k++, l--)
        swap(v[k],v[l]);

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, temp;
    vector<int> v;

    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    
    if(prev_permutation(v)){
        for(int i=0; i<n; i++)
            cout << v[i] << ' ';
    }
    else
        cout << -1;
        
}
