//C Program to find the number of leaf nodes in a Tree.

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
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Function to count the number of leaf nodes
int countLeafNodes(struct Node *node)
{
    // Base case: If the node is NULL, return 0
    if (node == NULL)
    {
        return 0;
    }
    // If the node is a leaf (no children), return 1
    if (node->left == NULL && node->right == NULL)
    {
        return 1;
    }
    // Recursively count leaf nodes in the left and right subtrees
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}
// Main function to demonstrate the counting of leaf nodes
int main()
{
    // Constructing the binary tree
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);
    // Count leaf nodes
    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes in the tree: %d\n", leafCount);
    return 0;
}