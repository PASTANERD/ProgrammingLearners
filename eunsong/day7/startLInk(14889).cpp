#include <iostream>
#include <vector>

using namespace std;

int s[20][20] = {0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> s[i][j];
    
    int ans=20*20*100;
    for(int i=0; i<(1<<n); i++){
        vector<int> first, second;
        for(int j=0; j<n; j++){
            if(i&(1<<j))
                first.push_back(j);
            else
                second.push_back(j);
        }
        if(first.size()!=n/2 && second.size()!=n/2) continue;
        int t1=0,t2=0;
        for(int j=0; j<n/2; j++){
            for(int k=0; k<n/2; k++){
                if(j == k) continue;
                //cout << first[j] << " " << first[k] <<  " "<< s[first[j]][first[k]]<< endl;
                //cout << second[j] << " " << second[k] << endl;
                t1 += s[first[j]][first[k]];
                t2 += s[second[j]][second[k]];
                //cout << t1 << " " << t2 << endl;
            }
        }
        ans = (ans > abs(t1-t2)) ? abs(t1-t2) : ans;
    }

    cout << ans << "\n";

    return 0;
}