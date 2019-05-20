#include<stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node* next;
};


struct node* Insert(struct node* head, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node)) ;
    temp->data = data;
    temp->next = NULL;
    if(head == NULL)
        head = temp;
    else{
        struct node* temp1 = head;
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return head;
}

void print(struct node* p){
    if(p == NULL)
        return;
    printf("%d", p->data);
    print(p->next);
}

void reverse_print(struct node* p){
    if(p == NULL)
        return;
    reverse_print(p->next);
    printf("%d", p->data);
}

int main() {
    struct node* head = NULL;
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,5);
    print(head);
    reverse_print(head);
	
}
