/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int solve(TreeNode* root, int ans){
        if(root == NULL){
            return 0;
        }
        ans = 10*ans + root -> val;             //More u go down more it get's multiply by 10
        if(root -> left == NULL && root -> right == NULL){
            return ans;
        }
        return solve(root->left, ans) + solve(root->right, ans);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        return solve(root, ans);
    }
};

int main(){

    return 0;
}