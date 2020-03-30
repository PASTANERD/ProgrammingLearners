//15654

#include <iostream>

using namespace std;

int N, M;
int ans[9];

void sub(int num[], int index){
    
    if(index == M){
        for(int i=0; i<M; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    
    for(int i=0; i<N; i++){

        if(index == 0){
            ans[index] = num[i];
            sub(num,index+1);
        }
        else{
            bool exist = false;
            for(int j=0; j<index; j++){
                if(ans[j] == num[i]){
                    exist = true; break;
                }
            }
            if(!exist){
                ans[index] = num[i];
                sub(num,index+1);}
            }
        }
}

int main(){
    
    cin >> N >> M;
    int num[N];
    for(int i=0; i<N; i++){
        cin >> num[i];
    }
    
    sort(num,num+N);
    
    sub(num,0);
}

