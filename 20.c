//WAP to insert the element into linear queue and delete three elements from the list. Display list after each insertion and deletion.

#include<stdio.h>
#define N 5

int FRONT=0, REAR=-1, ITEM,choice;
int q[N];

main()
{ 
    int choice;
    while(1)
    { 
        printf("Press 1 for insert: \n");
        printf("Press 2 for delete: \n");
        printf("Press 3 for display: \n");
        printf("Press 4 for quit: \n");

        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("You select the wrong choice! Thankyou \n");
            break;
        }
    }
    return 0;
}
insert()
{ 
    if(REAR==N-1)
    { 
        printf("Queue overflow");
    }
    else
    { 
        printf("Enter the item: \n");
        scanf("%d",&ITEM);
        REAR++;
        q[REAR]=ITEM;
    }
    return;
}
delete()
{ 
    if(REAR==FRONT-1)
    { 
        printf("Queue underflow");

    }
    else if(REAR==FRONT)
    {
        printf("This is the last element in the queue \n");
        printf("The deleted element is : %d",q[FRONT]);
        FRONT=0;
        REAR=-1;
    }
    else
    { 
        printf("Deleted item is : %d", q[FRONT]);
        FRONT++;
        // FRONT--;
        // printf("Deleted item is : %d", q[FRONT]);
    }
    return;
    
}
display()
{
    int i;
    if(REAR==FRONT-1)
    { 
        printf("no element in queue");
    }
    else
    { 
        for(i=FRONT; i<=REAR; i++)
        {
            printf("%d \n", q[i]);
          //  printf("front of the queue is %d \n",q[FRONT]);
           // printf("rear is %d\n",q[REAR]);
        }
    }
    return;
}

