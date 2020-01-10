#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int sum = 0;
    int num = 9;
    int boy[num];
    
    for(int i=0; i<num; i++){
        cin >> boy[i];
        sum += boy[i];
    }
    
    sort(boy, boy+num);
    
    for(int i=0; i<num-1; i++){
        for(int j=i+1; j<num; j++){
            if(sum - boy[i] - boy[j] == 100){
                for(int k=0; k<num; k++){
                    if(k!=i && k!=j)
                        cout << boy[k] << '\n';
                }
                return 0;
            }
        }
    }
}
