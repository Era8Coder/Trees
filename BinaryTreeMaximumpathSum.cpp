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

// -->> Below is the Code for finding the maximum path Sum <<--
class Solution {
public:
    int solve(TreeNode* root, int &res){
        if(root == NULL){       // Base Case
            return 0;
        }

        // Storing the sum from left and right of the Node
        int l = solve(root->left, res);
        int r = solve(root->right,res);

        int temp = max(max(l,r) + root->val, root->val);    // Getting Maximum from left and right side and then adding root value to it OR simply managing with the root value 
        int maxi = max(temp, l+r+root->val);    // We hadn't included the upper one path and we are playing on down path only <<-- :P
        res = max(res, maxi);

        return temp;        // Returning Temp 
    }

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};
// For this we have to analyse many cases when we are including above tree or not and when we managing it with root :)

int main(){

    return 0;
}