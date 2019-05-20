#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
};
struct node* head; //global so that we dont have to pass it as arguement to print() and insert()

void insert(int value)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node)); //typecasting as malloc returns a void pointer
    (*temp).data = value; //alt: temp->data = x;
    temp->next = head; // alt: (*temp).next = head;
    head = temp;
}

void print()
{
    struct node* temp = head;
    printf("List is: ");
    while(temp != NULL)
    {
        printf("%d", temp->data);
    }
    printf("\n");
}

int main()
{
    head = NULL; //Empty list
    printf("How many numbers");
    int n,i,x;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter the number ");
        scanf("%d", &x);
        insert(x);
        print();
    }
}
