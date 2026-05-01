#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    // Base case
    if (root == NULL)
        return 0;

    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recursive calls
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    // Creating tree manually
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int leafCount = countLeafNodes(root);

    printf("Number of leaf nodes: %d\n", leafCount);

    return 0;
}