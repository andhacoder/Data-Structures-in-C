#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    node* left;
    node* right;
};

int isBstUtil(struct node* root, int min, int max){
    if(root == NULL)
        return 1;
    if(root->data > min && root->data < max && isBinarySearchTree(root->left) && isBinarySearchTree(root->right))
        return 1;
    else
        return -1;
}

int isBinarySearchTree(struct node* root){
    return isBstUtil(struct node*root, INT_MIN, INT_MAX);
}
int main(){
    
}
