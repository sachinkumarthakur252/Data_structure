//C Program for finding the sum of all the nodes in a Tree.

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
// Function to calculate the sum of all nodes
int sumOfNodes(struct Node *node)
{
    // Base case: If the node is NULL, return 0
    if (node == NULL)
    {
        return 0;
    }
    // Return the data of the current node plus the sum of left and right subtrees
    return node->data + sumOfNodes(node->left) +
           sumOfNodes(node->right);
}
// Main function to demonstrate the sum of all nodes
int main()
{
    // Constructing the binary tree
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    // Calculate the sum of all nodes
    int totalSum = sumOfNodes(root);
    printf("Sum of all nodes in the tree: %d\n", totalSum);
    return 0;
}