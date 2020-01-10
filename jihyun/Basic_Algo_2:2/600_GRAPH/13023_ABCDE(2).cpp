//13023

#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
   
    int v, e;
    cin >> v >> e;

    bool ar[2000][2000] = {{false,}};
    vector<int> friends[2000];
    vector<pair<int, int>> edges;
    
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
        edges.push_back({a,b});
        edges.push_back({b,a});
        ar[a][b] = true;
        ar[b][a] = true;
    }
    e *= 2;
    
    for(int i=0; i<e; i++){
        for(int j=0; j<e; j++){
            int a1 = edges[i].first;
            int a2 = edges[i].second;
            int a3 = edges[j].first;
            int a4 = edges[j].second;
            
            if(!ar[a2][a3] || a1 == a3 || a1 == a4 || a2 == a3 || a2 == a4)
                continue;
            
            for(int a5 : friends[a4]){
                if(a5 == a1 || a5 == a2 || a5 == a3 || a5 == a4)
                    continue;
                else{
                    cout << "1";
                    return 0;
                }
            }
        }
    }
   
    cout << "0";
}
