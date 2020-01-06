//13023

#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
   
    int v, e;
    cin >> v >> e;

    vector<int> friends[2000];
    
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    
    int a1, a2, a3, a4, a5;

    for(a1=0; a1<e; a1++){
        for(int j=0; j<friends[a1].size(); j++){
            a2 = friends[a1][j];
            if(a2 == a1)
                continue;
            for(int k=0; k<friends[a2].size(); k++){
                a3 = friends[a2][k];
                if(a3 == a1 || a3 == a2)
                    continue;
                for(int l=0; l<friends[a3].size(); l++){
                    a4 = friends[a3][l];
                    if(a4 == a1 || a4 == a2 || a4 == a3)
                        continue;
                    for(int m=0; m<friends[a4].size(); m++){
                        a5 = friends[a4][m];
                        if(a5 == a1 || a5 == a2 || a5 == a3 || a5 == a4)
                            continue;
                        else{
                            cout << "1"; return 0;
                        }
                    }
                }
            }
        }
    }
    
    cout << "0";
}
