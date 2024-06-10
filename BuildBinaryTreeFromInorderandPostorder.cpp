#include<bits/stdc++.h>
using namespace std;

/*
    In case of POSTORDER -> We First Build The Right Sub - Tree
    In case of PREORDER  -> We First Build The Left Sub - Tree

*/

struct node{
    public:
        int data;
        node* left;
        node* right;

        node(int val){
            data = val;
            left = NULL;
            right= NULL;
        }
};  

int search(vector<int> &inorder, int start, int end, int curr){
    for(int i=start; i<=end; i++){
        if(inorder[i] == curr){
            return i;
        }
    }
    return -1;
}

node* build_tree(vector<int> &postorder, vector<int> &inorder, int start, int end){
    int n = postorder.size();
    static int idx = n - 1;
    if(idx < 0 || start > end){
        return NULL;
    }
    
    int curr = postorder[idx];
    idx--;
    node* new_node = new node(curr);

    int pos = search(inorder, start, end, curr);
    
    new_node -> right= build_tree(postorder, inorder, pos+1, end);      // First right side call since => We are building from right side Using (idx--)
    new_node -> left = build_tree(postorder, inorder, start, pos-1);

    return new_node;
}

void display(node* root){
    if(root == NULL){
        return;
    }

    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

int main(){
    vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> postorder= {8, 4, 5, 2, 6, 7, 3, 1};
    int n =  inorder.size();
    node* root = build_tree(postorder, inorder, 0, n-1);
    display(root);
    return 0;
}