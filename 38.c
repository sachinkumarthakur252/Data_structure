//C Program to Traverse the Tree Recursively.

#include <stdio.h>
#include <stdlib.h>
// Structure of the node in the binary tree
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
// In-order traversal (Left, Root, Right)
void inOrder(struct Node *node)
{
    if (node == NULL)
        return;
    inOrder(node->left);       // Visit left subtree
    printf("%d ", node->data); // Visit root
    inOrder(node->right);      // Visit right subtree
}
// Pre-order traversal (Root, Left, Right)
void preOrder(struct Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data); // Visit root
    preOrder(node->left);      // Visit left subtree
    preOrder(node->right);     // Visit right subtree
}
// Post-order traversal (Left, Right, Root)
void postOrder(struct Node *node)
{
    if (node == NULL)
        return;
    postOrder(node->left);     // Visit left subtree
    postOrder(node->right);    // Visit right subtree
    printf("%d ", node->data); // Visit root
}
// Main function to demonstrate the traversals
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
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