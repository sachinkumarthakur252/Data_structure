//C program to implement the queue data structure using a linked list.
#include<stdio.h>
#include<stdlib.h>
struct node
{ 
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
typedef struct node node;

enqueue(int x)
{ 
    node *ptr, *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;

    if(front==NULL && rear==NULL)
    { 
        front=rear=newnode;
    }
    else
    { 
        rear->next=newnode;
        rear=newnode;
    }
}

dequeue()
{ 
    node *temp;
    temp=front;
    if(front==NULL && rear==NULL)
    { 
        printf("Queue is empty!\n");
    }
    else
    { 
        printf("Deleted item is %d:\n",temp->data);
        front=front->next;
        free(temp);
    }
}

display()
{ 
    node *temp;
    temp=front;
    if(front==NULL && rear==NULL)
    { 
        printf("Queue is empty!\n");
    }
    else
    printf("Items are:\n");
    while(temp!=NULL)
    { 
        printf("%d\n", temp->data);
        temp=temp->next;
    }
}

peek()
{ 
    if(front==NULL && rear==NULL)
    { 
        printf("Queue is empty!\n");
    }
    else
    { 
        printf("First item is: %d\n",front->data);
    }
}
void main()
{ 
    enqueue(4);
    enqueue(2);
    enqueue(9);
    peek();
    display();
    dequeue();
    display();
    peek();
}