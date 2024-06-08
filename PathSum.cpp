/*Given the root of a binary tree and an integer targetSum, 
return true if the tree has a root-to-leaf path such that 
adding up all the values along the path equals targetSum.
A leaf is a node with no children.
*/

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

bool path_sum(node* root, int tgt_sum){          // we have to find whether there exists path from root to leaf which has sum = tgt_sum
    if(root->left==NULL && root->right == NULL && (tgt_sum-root->data) == 0){
        return true;
    }

    if(root->left==NULL && root->right == NULL && (tgt_sum-root->data) != 0){
        return false;
    }

    return path_sum(root->left,tgt_sum-root->data) || path_sum(root->right,tgt_sum-root->data);
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right= new node(3);
    root->left->left = new node(4);
    root->left->right= new node(5);
    root->right->left= new node(6);
    root->right->right=new node(7);
    cout << path_sum(root,10) << endl;
    cout << path_sum(root,13) << endl;
    return 0;
}