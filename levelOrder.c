
// To traverse the tree via level order
void levelOrder(struct node* root){
    if(root == NULL)
        return;
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty()){
        struct node* current = Q.front();
        Q.pop();
        printf("%c",current->data);
        if(current->left != NULL)
            Q.push(current->left);
        if(current->right != NULL)
            Q.push(current->right);
    }
}


