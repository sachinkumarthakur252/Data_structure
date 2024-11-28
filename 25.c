//Write a program to insert, delete, and display in Doubly Linked List

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *start = NULL;
typedef struct node node;

void insert_beg()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    start=temp;
}

void insert_end()
{
    node *temp, *ptr;
    temp = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
}

void insert_pos()
{
    node *temp, *ptr;
    int pos, i = 1;
    temp = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        printf("Enter the position: ");
        scanf("%d", &pos);
        ptr = start;
        while (i < pos - 1)
        {
            ptr = ptr->next;
            i++;
        }
        temp->next = ptr->next;
        temp->prev = ptr;
        ptr->next = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = temp;
        }
    }
}

void delete_beg()
{
    node *temp;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = start;
        start = start->next;
        start->prev = NULL;
        free(temp);
    }
}

void delete_end()
{
    node *temp, *ptr;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = NULL;
        free(temp);
    }
}

void delete_pos()
{
    node *temp, *ptr;
    int pos, i = 1;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Enter the position: ");
        scanf("%d", &pos);
        temp = start;
        while (i < pos - 1)

        {
            ptr = temp;
            temp = temp->next;
            i++;
        }
        ptr->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = ptr;
        }
        free(temp);
    }
}

void display()
{
    node *temp;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_beg();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            insert_pos();
            break;
        case 4:
            delete_beg();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            delete_pos();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}