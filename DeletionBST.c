//Delete a node from BST
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

//Function to find a minimum in a tree
struct node* findMin(struct node* root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

struct node* Delete(struct node* root, int data){
    if(root == NULL)
        return root;
    else if(data < root->data)
        root->left = Delete(root->left, data);
    else if(data > root->data)
        root->right = Delete(root->right, data);
    else{
        //Case1: No Child
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        //Case2: One Child(right)
        else if(root->left == NULL){
            struct node* temp = root;
            root = root->right;
            free(temp);
        }
        //One Child(left)
        else if(root->right == NULL){
            struct node* temp = root;
            root = root->left;
            free(temp);
        }
        //Case 3: 2 children
        else{
            struct node* temp = findMin(root->right);
            root->data = temp->data;
			root->right = Delete(root->right,temp->data);
        }
    }
    return root;
}

//Function to visit nodes in Inorder
void Inorder(struct node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}
 
// Function to Insert Node in a Binary Search Tree
struct node* Insert(struct node *root,int  data) {
	if(root == NULL) {
		root = (node*)malloc(sizeof(node));
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}

int main() {
	/*Code To Test the logic
	  Creating an example tree
	                    5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
	struct node* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4); 
	root = Insert(root,1); root = Insert(root,11);

	// Deleting node with value 5, change this value to test other cases
	root = Delete(root,5);

	//Print Nodes in Inorder
	printf("Inorder: ");
	Inorder(root);
	printf("\n");
}
