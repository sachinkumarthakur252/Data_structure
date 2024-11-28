//C Program to Print all the Paths from the Root to the Leaf in a Tree

#include <stdio.h>
#include <stdlib.h>
// Structure of a node in the binary tree
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
// Utility function to print a path from the root to a leaf
void printArray(int path[], int pathLength)
{
    for (int i = 0; i < pathLength; i++)
    {
        printf("%d ", path[i]);
    }
    printf("\n");
}
// Recursive function to print all paths from root to leaves
void printPathsRecur(struct Node *node, int path[], int pathLength)
{
    if (node == NULL)
        return;
    // Append this node to the path array
    path[pathLength] = node->data;
    pathLength++;
    // If it's a leaf, print the path
    if (node->left == NULL && node->right == NULL)
    {
        printArray(path, pathLength);
    }
    else
    {
        // Otherwise, recur down to both subtrees
        printPathsRecur(node->left, path, pathLength);
        printPathsRecur(node->right, path, pathLength);
    }
}
// Function to initiate the path finding
void printPaths(struct Node *node)
{
    int path[1000]; // Large enough to hold any possible path
    printPathsRecur(node, path, 0);
}
// Main function to demonstrate the program
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printf("All root-to-leaf paths:\n");
    printPaths(root);
    return 0;
}