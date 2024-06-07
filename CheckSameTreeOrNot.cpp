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

bool same_tree(node* p, node* q){           // To check whether tree's rooted at p and q are same or not
    if(p==NULL && q==NULL){     // this means we are at the extremities
        return true;
    }

    if(p==NULL || q==NULL || p->data != q->data){
        return false;
    }

    return same_tree(p->left,q->left)&&same_tree(p->right,q->right);
}

int main(){

    return 0;
}