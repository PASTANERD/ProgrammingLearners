
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

#define A 65

using namespace std;

vector<char> node;
vector<pair<char, char> > childs;

void preorder(int v){
    char left = childs[v].first, right = childs[v].second;
    // compute current node
    cout << (char)(v+A) << "["<<v <<"]"<< " " << left << "["<< (int)(left-A)<< "] " << right << "[" << (int)(right - A) << "]\n";
    // cout << (char)(v+A);
    
    // visit left child
    if(left != '.') {
        int next = left - A;
        preorder(next);
    }
    // visit right child
    if(right != '.') {
        int next = right - A;
        preorder(next);
    }
}

void inorder(int v){
    char left = childs[v].first;
    char right = childs[v].second;
    
    // visit left child
    if(left != '.') {
        int next = left - A;
        inorder(next);
    }
    
    // compute current node
    cout << (char)(v+A) << " " << left << " " << right << '\n';
    
    // visit right child
    if(right != '.') {
        int next = right - A;
        inorder(next);
    }
}

void postorder(int v){
    char left = childs[v].first;
    char right = childs[v].second;
    
    // visit left child
    if(left != '.') {
        int next = left - A;
        postorder(next);
    }
    // visit right child
    if(right != '.') {
        int next = right - A;
        postorder(next);
    }

    // compute current node
    cout << (char)(v+A) << " " << left << " " << right << '\n';
    
}

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

    // for (int i = 0 ; i < N ; i++){
    //     cout << node[i]<< "[" << i << "]" << ": {" << childs[i].first << "," << childs[i].second << "}\n";
    // }
    
    // cout << node[3] << ": {" << childs[3].first << ", " << childs[3].second << "}\n";
    preorder(0);
    // cout << '\n';
    // inorder(0);
    // cout << '\n';
    // postorder(0);
    

    return 0;
}
