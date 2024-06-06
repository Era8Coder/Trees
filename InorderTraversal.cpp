#include<bits/stdc++.h>
using namespace std;

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

void inorder_recursive(node* root){
    if(root == NULL){
        return;
    }

    inorder_recursive(root->left);
    cout << root->data << " ";
    inorder_recursive(root->right);
}

void inorder_iterative(node* root){
    if(root == NULL){
        return;
    }

    node* curr = root;
    stack<node*> stk;

    while(!stk.empty() || curr != NULL){
        if(curr != NULL){
            stk.push(curr);
            curr = curr -> left;
        }else{
            node* temp = stk.top();
            stk.pop();
            cout << temp->data << " ";
            curr = temp -> right;
        }
    }
}

/*
                                    1
                                   / \ 
                                  2   3
                                 /\   /\  
                                4  5 6  7
*/

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right= new node(3);
    root->left->left = new node(4);
    root->left->right= new node(5);
    root->right->left= new node(6);
    root->right->right=new node(7);
    inorder_recursive(root);
    cout << endl;
    inorder_iterative(root);
    return 0;
}