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

//To Find height of a BST
int FindHeight(struct BstNode* root){
    if(root == NULL){
        return -1;
    }
    int LeftHeight = FindHeight(root->left);
    int RightHeight = FindHeight(root->right);
    return max(LeftHeight,RightHeight)+1;
}
int main(){
	
}
