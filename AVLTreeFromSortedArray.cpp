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

node* solve(vector<int> &v, int left, int right){
    if(left > right){
        return NULL;
    }

    int mid = (left + right) / 2;
    node* root = new node(v[mid]);

    root->left = solve(v,left,mid-1);
    root->right= solve(v,mid+1,right);

    return root;
}

void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7};
    int left = 0;
    int right= v.size() - 1;
    node* root = solve(v,left,right);
    postorder(root);
    return 0;
}