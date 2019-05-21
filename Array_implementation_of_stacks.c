//Array implementation of stacks
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void push(int x){
    if(top == MAX_SIZE -1){
        printf("ERROR: Stack Overflow");
        return;
    }
    A[++top] = x;
}

void pop(){
    if(top == -1){
        printf("ERROR: No element in stack to pop");
        return;
    }
    top--;
}

int peek(){
    
    return A[top];
}

void IsEmpty(){
    if(top == -1)
        printf("Stack is empty");
    else 
        printf("Stack is not empty");
}

void print(){
    printf("Stack:");
    for(int i = 0; i <= top; i++)
        printf("%d", A[i]);
}

int main() {
	IsEmpty();
	push(2);
	push(4);
	push(6);
	push(5);
	print();
	cout<<peek();
	
}
