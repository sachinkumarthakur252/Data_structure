// Write a program to insert and traverse in Binary Search Tree.
#include <stdio.h>
#include <stdlib.h>
// Structure for a node in the BST
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
// Function to insert a new node in the BST
struct Node *insert(struct Node *node, int data)
{
    if (node == NULL)
    {
        return newNode(data);
    }
    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
    return node;
}
// In-order traversal (Left, Root, Right)
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
// Pre-order traversal (Root, Left, Right)
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
// Post-order traversal (Left, Right, Root)
void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
// Main function to demonstrate insertion and traversal in BST
int main()
{
    struct Node *root = NULL;
    // Inserting elements into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");
    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");
    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");
    return 0;
}
