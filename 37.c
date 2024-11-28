//C program to demonstrate delete operation in Binary Search Tree.

#include <stdio.h>
#include <stdlib.h>
// Structure of a node in the BST
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
// Function to find the minimum value node in the right subtree
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
// Function to delete a node from the BST
struct Node *deleteNode(struct Node *root, int data)
{
    // Base case: If the tree is empty
    if (root == NULL)
    {
        return root;
    }
    // Recur down the tree
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node *temp = minValueNode(root->right);
        // Copy the inorder successor's data to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
// Main function to demonstrate the delete operation in a BST
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
    printf("In-order traversal of the original tree:\n");
    inOrder(root);
    printf("\n");
    // Deleting node with value 20 (leaf node)
    printf("Deleting 20...\n");
    root = deleteNode(root, 20);
    printf("In-order traversal after deleting 20:\n");
    inOrder(root);
    printf("\n");
    // Deleting node with value 30 (node with one child)
    printf("Deleting 30...\n");
    root = deleteNode(root, 30);
    printf("In-order traversal after deleting 30:\n");
    inOrder(root);
    printf("\n");
    // Deleting node with value 50 (node with two children)
    printf("Deleting 50...\n");
    root = deleteNode(root, 50);
    printf("In-order traversal after deleting 50:\n");
    inOrder(root);
    printf("\n");
    return 0;
}