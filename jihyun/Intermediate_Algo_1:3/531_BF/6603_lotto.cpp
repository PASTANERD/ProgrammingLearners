//6603

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Next_combination(vector<int> c, vector<int> v){
    for(int i=0; i<c.size(); i++){
        if(c[i]==1)
            cout << v[i] << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    do{
        int size;
        cin >> size;
        
        if(size == 0)
            break;
        
        vector<int> set(size);
        for(int i=0; i<size; i++)
            cin >> set[i];
        
        vector<int> c;
        int put = 1;
        for(int i=0; i<size; i++){
            if(i==6) put = 0;
            c.push_back(put);
        }
        
        do{
            Next_combination(c, set); cout << '\n';
        }while(prev_permutation(c.begin(), c.end()));
        
        cout << '\n';
    }while(1);
}



