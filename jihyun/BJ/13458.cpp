//13458
#include <iostream>

using namespace std;

int main(){
    int N, B, C;
    cin >> N;
    int people[N];
    
    long long cnt = 0;
    
    for(int i=0; i<N; i++)
        cin >> people[i];
    
    cin >> B >> C;
    
    for(int i=0; i<N; i++)
        people[i] -= B;

    cnt += N;
    
    for(int i=0; i<N; i++){
        if(people[i]<=0) continue;
        
        cnt += people[i] / C;

        if(people[i] % C != 0)
            cnt ++;
    }
    
    cout << cnt;
}

