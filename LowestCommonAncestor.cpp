/*  
    Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between 
    two nodes p and q as the lowest node in T that has both p and q as descendants 
    (where we allow a node to be a descendant of itself).”
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowest_common_ancestor(TreeNode* root, TreeNode* p, TreeNode* q){
    // We will use the Recursive Approach to Solve This
    if(root == NULL){
        return NULL;
    }

    if(root -> val == p -> val || root -> val == q -> val){
        return root;
    }       

    TreeNode* left = lowest_common_ancestor(root->left, p, q);
    TreeNode* right= lowest_common_ancestor(root->right,p, q);

    if(left == NULL)
    {
        return right;
    }
    if(right== NULL)
    {
        return left;
    }
    return root;
}

int main(){ 
    
    return 0;
}