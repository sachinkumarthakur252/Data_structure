//To push and pop element through stack
#include<stdio.h>
#define MAX 5

int TOP=-1;
int s[MAX];

main()
{ 
    int choice;
    while(1)
    { 
        printf("Press 1 for push: \n");
        printf("Press 2 for pop: \n");
        printf("Press 3 for display: \n");
        printf("Press 4 for quit: \n");

        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
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
            exit(1);
            break;
        default:
            printf("You select the wrong choice! Thankyou \n");
            break;
        }
    }
    return 0;
}
push()
{ 
    int item;
    if(TOP==(MAX-1))
    { 
        printf("Stack are over-flow!\n");
    }
    else
    { 
        printf("Enter the item for pused in the stack: ");
        scanf("%d",&item);
        TOP=TOP+1;
        s[TOP]=item;
    
    }
    return;
}
pop()
{ 
    if(TOP==-1)
    { 
        printf("Stack are under flow!\n");

    }
    else
    { 
        printf("Poped element is %d \n",s[TOP]);
        TOP=TOP-1;
    }
    return;
}
display()
{ 
    int i;
    if(TOP==-1)
    {
        printf("Stack is empty! sorry\n");
    }
    else
    { 
        printf("Stack elements is:\n");
        for(i=TOP; i>=0; i--)
        { 
            printf("%d\n",s[i]);
        }
    }
    return;
}
