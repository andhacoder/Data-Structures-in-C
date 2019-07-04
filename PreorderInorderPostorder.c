//Binary Tree- level order traversal
#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    node* left;
    node* right;
};

//To insert nodes in the binary tree
struct node* insert(struct node*root, int data){
    if(root == NULL){
        root = (node*)malloc(sizeof(node));
        root->data = data;
        root->left = root->right = NULL;
    }
    else if(data <= root->data)
        root->left = insert(root->left,data);
    else
        root->right = insert(root->right,data);
    return root;
}

// To traverse the tree via Pre Order(data-left-right)
void preOrder(struct node* root){
    if(root == NULL)
        return;
    printf("%c",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// To traverse the tree via Pre Order(left-data-right)
void inOrder(struct node* root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%c",root->data);
    inOrder(root->right);
}

// To traverse the tree via Post Order(left-right-data)
void postOrder(struct node* root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c",root->data);
}

int main() {
/*Code To Test the logic
	  Creating an example tree
	        M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
	node* root = NULL;
	root = insert(root,'M'); root = insert(root,'B');
	root = insert(root,'Q'); root = insert(root,'Z'); 
	root = insert(root,'A'); root = insert(root,'C');
	//Print Nodes in Preorder. 
	printf("Preorder: ");
	preOrder(root);
	printf("\n");
	//Print Nodes in Inorder
	printf("Inorder: ");
	inOrder(root);
	printf("\n");
	//Print Nodes in Postorder
	printf("Postorder: ");
	postOrder(root);
	printf("\n");
}
