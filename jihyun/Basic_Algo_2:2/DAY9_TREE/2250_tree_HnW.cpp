
#include<iostream>

using namespace std;

struct node{
    int parent = -1;
    int right;
    int left;
    int col;
    int row = -1;
};
node *tree;
int max_level = 1;

//left -> parent -> right
void inorder(int x){
    if(x == -1) return;
    static int cur_col = 1;
    inorder(tree[x].left);
    tree[x].col = cur_col++;
    inorder(tree[x].right);
}

void SetRow(int x){
    if(tree[x].row != -1) return;
    if(tree[tree[x].parent].row == -1)
        SetRow(tree[x].parent);
    tree[x].row = tree[tree[x].parent].row + 1;
    if(tree[x].row > max_level)
        max_level = tree[x].row;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;
    tree = new node[n+1];
    
    for(int i=1; i<=n; i++){
        int p, l, r;
        cin >> p >> l >> r;
        tree[p].left = l; tree[p].right = r;
        if(l!=-1)tree[l].parent = p;
        if(r!=-1)tree[r].parent = p;
    }
    
    //Find the root
    int root = 0;
    for(int i=1; i<=n; i++){
        if(tree[i].parent == -1){
            root = i; break;}
    }
    
    //Set column
    inorder(root);
    
    //Set row (level)
    tree[root].row = 1;
    for(int i=1; i<=n; i++){
        if(i==root) continue;
        SetRow(i);
    }
    
    //Find the maximum width
    int max_lv = 1, max_wid = 1;
    for(int lv = 1; lv <= max_level; lv++){
        int MIN = 10000, MAX = -1;
        for(int i=1; i<=n; i++){
            if(tree[i].row!=lv) continue;
            MIN = min(MIN, tree[i].col);
            MAX = max(MAX, tree[i].col);
        }
        if(max_wid < MAX-MIN+1){
            max_wid = MAX-MIN+1;
            max_lv = lv;
        }
    }
    cout << max_lv << ' ' << max_wid;
}
