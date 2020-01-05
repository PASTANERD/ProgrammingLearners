#include <iostream>

#define MAX 2000000000
#define MIN -2000000000

using namespace std;

void binary(int N){
    //cout << N << endl;
    if(N == 0) return;
    if(N % -2 == 0){
        binary(N/-2);
        cout << "0";
    }
    else{
        binary((N-1)/-2);
        cout << "1";
    }
    return;
}

int main()
{
    try
    {
        int N;
        cin >> N;
        
        if(N > MAX || N < MIN)
            throw N;
        //cout << -6 % -2 << 13 % -2 << endl;
        binary(N);
       cout << endl;
    }
    catch(int e)
    {
        cout << "error out of bound: " << e << '\n';
    }
    
    return 0;
}
