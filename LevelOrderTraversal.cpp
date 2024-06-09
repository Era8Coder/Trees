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

void level_order_vector(node* root, vector<vector<int>> &v){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    vector<int> x;
    while(!q.empty()){
        node* n = q.front();
        q.pop();
        if(n == NULL){
            // To check that we are at the end of the level
            if(!q.empty()){
                q.push(NULL);       // Marker for next line
                // cout << endl;       // Creating a separator
            }
            v.push_back(x);
            x.clear();
        }else{
            // cout << n->data << " ";
            x.push_back(n->data);
            if(n->left!=NULL) q.push(n->left);
            if(n->right!=NULL) q.push(n->right);
        }        
    }
}

void level_order(node* root){
    if(root == NULL) return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){  
        node* n = q.front();
        q.pop();
        if(n == NULL){
            // To check that we are at the end of the level
            if(!q.empty()){
                q.push(NULL);       // Marker for next line
                cout << endl;       // Creating a separator
            }
        }else{
            cout << n->data << " ";
            if(n->left!=NULL) q.push(n->left);
            if(n->right!=NULL) q.push(n->right);
        }
    }
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right= new node(3);
    root->left->left = new node(4);
    root->left->right= new node(5);
    root->right->left= new node(6);
    root->right->right=new node(7);
    level_order(root);
    return 0;
}
