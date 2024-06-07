#include<bits/stdc++.h>
using namespace std;
// For multiple cursors "Ctrl + Alt + Up/Down" :))
struct node{
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right= NULL;
    }
};

bool check(node* left, node* right){
    if(left == NULL && right == NULL){          // If both are NULL then return true since Both Equal
        return true;
    }

    if((left == NULL &&  right != NULL) || (left != NULL && right == NULL)){
        return false;
    }

    if(left->data != right->data){
        return false;
    }

    return check(left->left, right->right) & check(left->right, right->left);        // interesting Recursion :))
}

bool is_symmetric(node* root){
    return check(root->left, root->right);
}

int main(){ 
    node* root = new node(1);
    root->left = new node(2);
    root->right= new node(2);
    root->left->left = new node(4);
    root->left->right= new node(5);
    root->right->left= new node(5);
    root->right->right=new node(4);
    cout << is_symmetric(root) << endl;
    return 0;
}