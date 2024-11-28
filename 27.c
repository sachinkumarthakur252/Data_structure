//write a c program to demonstrate the working of stack using linked list.

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;
typedef struct node node;
void push()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
}
void pop()
{
    node *temp;
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        temp=top;
        top=top->next;
        free(temp);
    }
}
void display()
{
    node *temp;
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}