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
    struct node* temp = (node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    struct node* temp2 = head;
    while(temp2 != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

void print()
{
    struct node* temp = head;
    while(temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Delete(int n)
{
    struct node* temp1 = head;
    if(n == 1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    int i;
    for(i = 0; i < n-2; i++)
    temp1 = temp1->next;
    struct node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

int main() 
{
    head = NULL; //empty list
    insert(2);
    insert(4);
    insert(6);
    insert(5); //List:2,4,6,5
    print();
    int n;
    printf("Enter a position");
    scanf("&d", n);
    Delete(n);
    print();
}
