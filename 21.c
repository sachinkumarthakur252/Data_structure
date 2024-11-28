//WAP to insert the elements into circular queue and delete 4 elements from the list. Display list after each insertion and deletion.
#include<stdio.h>
#define n 5
int cqueue[n];
int front=-1;
int rear=-1;

void encqueue(int x)
{ 
    if(front==-1 && rear==-1)
    { 
        front=rear=0;
        cqueue[rear]=x;
    }
    else if((rear+1)%n==front)
    { 
        printf("\nQueue is underflow!");
    }
    else
    {
        rear=(rear+1)%n;
        cqueue[rear]=x;
    }
}
void decqueue()
{ 
    if(front==-1 && rear==-1)
    { 
        printf("\nQueue is empty!");
    }
    else if(front==rear)
    
    { 
        printf("\nDeleted item is: %d",cqueue[front]);
        front=rear=-1;
    }
    else

    { 
        printf("\nDeleted item is: %d",cqueue[front]);
        front=(front+1)%n;
    }
}
void display()
{ 
    //int i=front;
    int i;
    if(front==-1 && rear==-1)
    { 
        printf("\nQueue is empty!");
    }
    else
    {
        printf("\nItems is:\n");
        //while(i!=rear)
        for(i=front; i!=rear; i=(i+1)%n)
        { 
            printf("%d\n", cqueue[i]);
           // i=(i+1)%n;
        }
        printf("%d", cqueue[rear]);
    }
}

void peek()
{ 
    if(front==-1 && rear==-1 )
    { 
        printf("\nQueue is empty!");
    }
    else
    { 
        printf("\nFirst item is: %d ",cqueue[front]);
    }
}

void main()
{ 
    encqueue(3);
    encqueue(5);
    encqueue(8);
    encqueue(1);
    encqueue(7);
    display();
    encqueue(9);
    decqueue();
    display();
    decqueue();
    decqueue();
    encqueue(33);
    peek();
    display();

}