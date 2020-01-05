#include <iostream>

#define MAXT 100
#define MAXN 1000000

using namespace std;

bool isPrime[MAXN + 1];
int prime[MAXN];
int pn = 0;

void Eratosthenes(){
    for(int i=2; i<MAXN; i++){
        if(!isPrime[i]){
            prime[pn++] = i;
            for(int j=2; j*i < MAXN; j++)
                isPrime[j*i] = true; 
        }
    }
}

int main(){
    try
    {
        Eratosthenes();

        cin.tie(NULL);
        ios_base::sync_with_stdio(false);

        

        int T;
        cin >> T;
        if(T > MAXT)
            throw T;
        
        for(int i = 0; i < T; i++){
            int N;
            cin >> N;
            if(N > MAXN && N <= 2)
                throw N;
            
            if(N % 2 == 1)
                continue;
            else{
                int count = 0;
                for(int j=0 ; prime[j] <= N/2; j++){
                    //cout << prime[j] << endl;
                    if(!isPrime[N-prime[j]])
                        count++;
                }
                cout << count << "\n";
            }
        }
    }
    catch(int e)
    {
        cout << "error: out of bound: " << e << "\n";
    }
    
    return 0;
}