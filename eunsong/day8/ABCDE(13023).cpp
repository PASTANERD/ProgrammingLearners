 #include <iostream>
 #include <vector>

using namespace std;

 int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    
    vector<pair<int,int> > a;
    bool check[2000][2000] = {false};
    vector<int> near[2000];
    int from, to;
    for(int i=0; i<m; i++){
        cin >> from >> to;
        a.push_back(make_pair(from,to));
        a.push_back(make_pair(to,from));
        check[from][to] = true;
        check[to][from] = true;
        near[from].push_back(to);
        near[to].push_back(from);
    }

    int ans=-1;
    for(int i=0; i<m*2; i++){
        for(int j=0; j<m*2; j++){
            int A = a[i].first;
            int B = a[i].second;
            int C = a[j].first;
            int D = a[j].second;
            if(A==B || B==C || C==D || A==C || A==D || B==D) continue;
            if(!check[B][C])    continue;
            for(int E : near[D]){
                if(A==E || B==E || C==E || D==E) continue;
            }
            cout << 1 << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";

    return 0;
 }