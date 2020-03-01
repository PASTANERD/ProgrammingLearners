//16956

#include <iostream>
#include <vector>

using namespace std;
int R, C;
vector<vector<char>> p;
int d[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

void Print(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++)
            cout << p[i][j];
        cout << '\n';
    }
}

void BFS(int x, int y){
    for(int k=0; k<4; k++){
        int new_x = x+d[k][0], new_y = y+d[k][1];
        if(new_x < 0 || new_x >= R || new_y < 0 || new_y >= C)
            continue;
        if(p[new_x][new_y]=='S'){
            cout << 0;
            exit(0);
        }
        if(p[new_x][new_y]=='.')
            p[new_x][new_y] = 'D';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C;
    vector<pair<int,int>> wolf;
    
    for(int i=0; i<R; i++){
        vector<char> temp;
        for(int j=0; j<C; j++){
            char t;
            cin >> t;
            switch(t){
                case 'S': temp.push_back('S'); break;
                case 'W': temp.push_back('W'); wolf.push_back({i,j}); break;
                default: temp.push_back('.');
            }
        }
        p.push_back(temp);
    }
    
    if(wolf.size() == 0){
        cout << 1 << '\n';
        Print();
        return 0;
    }

    for(auto i=wolf.begin(); i!=wolf.end(); i++)
        BFS(i->first,i->second);
    
    cout << 1 << '\n';
    Print();
}



