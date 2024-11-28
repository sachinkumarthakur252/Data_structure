// write a c program to construct a singly linked list and perform insertion, deletion and display operations?
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertEnd(struct Node **head_ref, int new_data)
{
    struct Node *newNode = createNode(new_data);
    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }
    struct Node *last = *head_ref;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

// Function to delete a node by value
void deleteNode(struct Node **head_ref, int key)
{
    struct Node *temp = *head_ref, *prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        free(temp);             // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to display the linked list
void displayList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the linked list operations
int main()
{
    struct Node *head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    printf("Linked List after insertion: ");
    displayList(head);

    deleteNode(&head, 20);
    printf("Linked List after deletion of 20: ");
    displayList(head);

    deleteNode(&head, 10);
    printf("Linked List after deletion of 10: ");
    displayList(head);

    deleteNode(&head, 30);
    printf("Linked List after deletion of 30: ");
    displayList(head);

    return 0;
}