#include<bits/stdc++.h>
using namespace std;

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

void postorder_recursive(node* root){
    if(root == NULL){
        return;
    }

    postorder_recursive(root->left);
    postorder_recursive(root->right);
    cout << root->data << " ";
}

void postorder_iterative(node* root){
    stack<node*> stk;
    node* curr = root;
    while(curr != NULL || !stk.empty()){
        if(curr != NULL){
            stk.push(curr);         // Push current into Stack
            curr = curr -> left;
        }else{
            node* prev_node = stk.top()->right;
            if(prev_node == NULL){
                prev_node = stk.top();
                stk.pop();
                cout << prev_node->data << " ";
                while(!stk.empty() && prev_node == stk.top()->right){
                    prev_node = stk.top();
                    stk.pop();
                    cout << prev_node->data << " ";
                }
            }else{
                curr = prev_node;
            }
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
    postorder_recursive(root);
    cout << endl;
    postorder_iterative(root);
    return 0;
}