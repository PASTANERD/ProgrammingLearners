
/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/1697
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define A 65

using namespace std;

vector<char> node;
vector<pair<char, char> > childs;

// void preorder(int v){
//     queue<int> q;
//     q.push(v);
//     while(!q.empty()){
//         int current = q.front();
//         q.pop();
//         char left = childs[current].first, right = childs[current].second;
//         cout << (char)(current + A);
//         if(left != '.') q.push(left-A);
//         if(right != '.') q.push(right-A);
//     }
// }

// void inorder(int v){
    
// }

// void postorder(int v){
    
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for(int i = 0 ; i < N ; i++){
        char parent, left, right;
        cin >> parent >> left >> right;
        node.push_back(parent);
        childs.push_back(make_pair(left, right));
    }

    for (int i = 0 ; i < N ; i++){
        cout << node[i] << ": {" << childs[i].first << "," << childs[i].second << "}\n";
    }
    
    preorder(0);
    // cout << '\n';
    // inorder(0);
    // cout << '\n';
    // postorder(0);
    

    return 0;
}
