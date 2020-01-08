
#include<iostream>

using namespace std;
struct node{
    int left;
    int right;
};
node tree[27];

void preorder(int x){
    if(x == -1) return;
    cout << (char)(x+'A');
    preorder(tree[x].left);
    preorder(tree[x].right);
}

void inorder(int x){
    if(x == -1) return;
    inorder(tree[x].left);
    cout << (char)(x+'A');
    inorder(tree[x].right);
}

void postorder(int x){
    if(x == -1) return;
    postorder(tree[x].left);
    postorder(tree[x].right);
    cout << (char)(x+'A');
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int num;
    cin >> num;
    
    while(num--){
        char p, l, r;
        cin >> p >> l >> r;
        
        if(l == '.')
            tree[p-'A'].left = -1;
        else
            tree[p-'A'].left = l-'A';
        
        if(r == '.')
            tree[p-'A'].right = -1;
        else
            tree[p-'A'].right = r-'A';
    }
    preorder(0); cout << '\n';
    inorder(0); cout << '\n';
    postorder(0); cout << '\n';
}



