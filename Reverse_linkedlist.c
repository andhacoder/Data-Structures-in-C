//Deleting node at the nth position
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head;

void insert(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
        return;
    }
    struct node* temp2 = head;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

void reverse()
{
    struct node *current,*prev,*next;
    current = head;
    prev = NULL;
    while( current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void print()
{
    struct node* temp = head;
    while(temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    reverse();
    print();
}
