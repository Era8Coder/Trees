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

class BSTIterator {
    stack<TreeNode*> stk;

    void pushAll(TreeNode* node){
        for(auto temp = node; node != NULL; node = node -> left){
            stk.push(node);
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = stk.top();
        stk.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

int main(){

    return 0;
}