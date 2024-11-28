// Write a C program to perform operations on Binary Search Tree?
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to search for a value in the BST
struct Node *search(struct Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }

    if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

// Function for in-order traversal of the BST
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function to demonstrate BST operations
int main()
{
    struct Node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. In-order Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Inserted %d into the BST.\n", value);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            struct Node *result = search(root, value);
            if (result != NULL)
            {
                printf("Value %d found in the BST.\n", value);
            }
            else
            {
                printf("Value %d not found in the BST.\n", value);
            }
            break;
        case 3:
            printf("In-order Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}