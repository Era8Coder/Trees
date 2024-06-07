#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int _data){
        data = _data;
        left = NULL;
        right= NULL;
    }
};

int height(node* root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right= new node(3);
    root->left->left = new node(4);
    root->left->right= new node(5);
    root->right->left= new node(6);
    root->right->right=new node(7);
    cout << height(root) << endl;
    return 0;
}