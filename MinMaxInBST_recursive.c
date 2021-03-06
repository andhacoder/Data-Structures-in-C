//Simple program to find minimum and maximum value in a BST 
#include <stdio.h>
#include <stdlib.h>

//Definition of node for BST
struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

//Function to create a node in heap
struct BstNode* GetNewNode(int data){
   struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode)); //typecasting BstNode;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
}

//To insert data in root node, returns address of root node
struct BstNode* insert(struct BstNode* root, int data){
    if(root == NULL){
        root = GetNewNode(data);
    }
    else if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

//To search an element in a BST
bool search(struct BstNode* root, int data){
    if(root == NULL)
        return false;
    else if(data <= root->data){
        return search(root->left, data);
    }
    else return search(root->right, data);
}
//To find minimum element in a BST
int FindMin(struct BstNode* root){
    if(root == NULL){
        cout<<"Error: The tree is empty";
        return -1;
    }
    else if(root->left == NULL)
      return root->data;
    return FindMin(root->left);
}

//To find maximum element in a BST
int FindMax(struct BstNode* root){
    if (root == NULL){
        cout<<"Error:The tree is empty";
        return -1;
    }
    else if(root->right == NULL)
      return root->data;
    return FindMax(root->right);
}
int main(){
}
