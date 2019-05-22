//Linked List implementation of stacks
#include <stdio.h>
#include <stdbool.h>

struct node{
    int data;
   struct node* next;
};

struct node* head = NULL;
int top = -1;

void push(int x){
    struct node* temp1;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp1 = top;
    top->next = temp
    
    top++;
    
}

void pop(){
    struct node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    delete temp; 
    top--;
}

int peek(){
    struct node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    return temp->data;
}

bool IsEmpty(){
    if(head == NULL)
        return true;
    else
        return false;
}

void print(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main() {
	push(2);
  push(4);
	push(6);
	push(5);
	cout<<peek();
	print();
	
}
