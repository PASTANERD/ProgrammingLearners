//14889

#include<iostream>

using namespace std;
int s[21][21] = {{0,},};
int min_d = -1;
int n;

bool check(int set,int x){
    if(set&(1<<(x-1)))
        return true;
    return false;
}

void min_diff(int set){
    int count = 0;  //포함되는 수의 갯수
    
    for(int i=1; i<=n; i++){
        if(check(set,i))
            count ++;
    }
    
    if(count != n/2)
        return;
    
    int start = 0, link = 0;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(check(set,i)&&check(set,j))
                start += s[i][j] + s[j][i];
            else if(!check(set,i) && !check(set,j))
                link += s[i][j] + s[j][i];
        }
    }
    
    if(abs(start-link) < min_d || min_d == -1)
        min_d = abs(start-link);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> s[i][j];
    
    for(int i=1; i<(1<<n); i++)
        min_diff(i);
    
    cout << min_d;
}
