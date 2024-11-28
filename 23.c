//Write a C program to perform all the operations on singly linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
typedef struct node node;
insert()
{
    node *temp, *ptr;
    temp = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp; 
    }
}
delete()
{
    node *temp, *ptr;
    int val;
    printf("Enter the value to be deleted: ");
    scanf("%d", &val);
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (head->data == val)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            if (ptr->next->data == val)
            {
                temp = ptr->next;
                ptr->next = ptr->next->next;
                free(temp);
                break;
            }
            ptr = ptr->next;
        }
    }
}

display()
{
    node *ptr;
    ptr = head;
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{

    int choice;
    while (1)
    {
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            delete();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
