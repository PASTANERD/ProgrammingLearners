#include<iostream>
#include<algorithm>

using namespace std;

char candy[50][50];
int n;

int max_candy(){
    int max = 0;
    
    for(int i=0; i<n; i++){
        
        //row
        int count = 1;
        for(int j=0; j<n-1; j++){
            if(candy[i][j] == candy[i][j+1])
                count++;
            else
                count = 1;
            
            if(count > max) max = count;
        }
        
        //col
        count = 1;
        for(int j=0; j<n-1; j++){
            if(candy[j][i] == candy[j+1][i])
                count++;
            else
                count = 1;
            if(count > max) max = count;
        }
    }
    
    return max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    int max = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> candy[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            //to right
            if(j+1 < n)
                if(candy[i][j] != candy[i][j+1]){
                    swap(candy[i][j], candy[i][j+1]);
                    if(max_candy() > max)
                        max = max_candy();
                    swap(candy[i][j], candy[i][j+1]);
                }
            
            //to down
            if(i+1 < n)
                if(candy[i][j] != candy[i+1][j]){
                    swap(candy[i][j], candy[i+1][j]);
                    if(max_candy() > max)
                        max = max_candy();
                    swap(candy[i][j], candy[i+1][j]);
                }
        }
    }
    
    cout << max;
}
