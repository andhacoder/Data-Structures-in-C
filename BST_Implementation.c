//Implementation of BST in C++
//Simple program to create BST and search a value in it
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
    BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode)); //typecasting BstNode;
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
int main(){
	BstNode* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
	root = insert(root,15);	
	root = insert(root,10);	
	root = insert(root,20);
	root = insert(root,25);
	root = insert(root,8);
	root = insert(root,12);
	// Ask user to enter a number.  
	int number;
	printf("Enter number be searched\n");
	scanf("%d",&number);
	//If number is found, print "FOUND"
	if(search(root,number) == true) printf("Found\n");
	else printf("Not Found\n");
}
