//Write a c program to count numbers of nodes using Linked list.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
typedef struct node node;
insert_at_end()
{
    node *temp, *new_node;
    int data;
    new_node = (node *)malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d", &data);
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
count_node()
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Number of node in linked list is:%d\n", count);
}
main()
{
    int choice;
    while (1)
    {
        printf("1.Insert\n2.Count\n3.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_at_end();
            break;
        case 2:
            count_node();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}
