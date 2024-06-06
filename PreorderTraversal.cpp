#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int val;
        node* left;
        node* right;

        node(int _val){
            val = _val;
            left= NULL;
            right=NULL;
        }
};

void preorder_recursive(node* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}

void preorder_iterative(node* root){
    if(root == NULL){   
        return;
    }

    node* curr = root;      // Making the Current Node
    stack<node*> stk;
    stk.push(curr);

    while(!stk.empty() || curr!=NULL){            // Till stack becomes empty or current node becomes NULL {Both must occur simultaneously}
        curr = stk.top();
        cout << curr->val << " ";
        stk.pop();
        if(curr->right != NULL){
            stk.push(curr->right);
        }
        
        if(curr->left != NULL){
            stk.push(curr->left);
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
    preorder_recursive(root);
    cout << endl;
    preorder_iterative(root);
    return 0;
}