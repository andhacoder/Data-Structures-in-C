//Doubly linked list implementation
#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* GetNewNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void InsertAtHead(int data){
    struct node* newnode = GetNewNode(data);
    if(head == NULL){
        head = newnode;
        return;
    }
    else{
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void print(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
}

void RevPrint(){
    node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->prev;
    }
    
}

int main() {
	InsertAtHead(5);
	InsertAtHead(6);
	InsertAtHead(4);
	InsertAtHead(2);
	print();
	RevPrint();
	
}
