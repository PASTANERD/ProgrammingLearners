#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    while(n != 0){
        cin >> n;

        int W[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cin >> W[i][j];
        }
        

        vector<int> d(n);
        for(int i=0; i<n; i++)
            d[i] = i;
        
        int answer = 4000000;
        do{
            bool ok = true;
            int sum = 0;
            if(d[0] != 0) break;
            for(int i=0; i<n-1; i++){
                if(W[d[i]][d[i+1]] == 0)    ok = false;
                else    
                {
                    sum += W[d[i]][d[i+1]];
                    //cout << sum << endl;
                }
            }
            if(ok && W[d[n-1]][d[0]] != 0){
                sum += W[d[n-1]][d[0]];
                answer = (sum<answer) ? sum : answer;
            }
        }while(next_permutation(d.begin(), d.end()));

        cout << answer << "\n";
    }

    return 0;
}