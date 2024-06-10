#include<bits/stdc++.h>
using namespace std;

/*
    It's one of the good problems -> I had seen it's Solution because of it only I was able to solve it <<--
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

node* build_tree(vector<int> &preorder, vector<int> &inorder, int start, int end){
    static int idx = 0;             // Globally Initialising the Variable :)
    if(start > end){                // That means we had crossed the Vector
        return NULL;
    }
    
    int curr = preorder[idx];
    idx++;
    node* n = new node(curr);

    if(start == end){
        return n;
    }

    int pos = search(inorder, start, end, curr);
    n->left = build_tree(preorder, inorder, start, pos - 1);
    n->right= build_tree(preorder, inorder, pos+1,end);
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
    vector<int> preorder = {1, 2, 4, 3, 5};
    vector<int> inorder = {4, 2, 1, 5, 3};
    int n = preorder.size();
    node* root = build_tree(preorder, inorder, 0, n-1);
    display(root);
    return 0;
}