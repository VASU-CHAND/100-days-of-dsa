#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// New Node create
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// LCA function
struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // If either n1 or n2 matches with root
    if (root->data == n1 || root->data == n2)
        return root;

    struct Node* left = LCA(root->left, n1, n2);
    struct Node* right = LCA(root->right, n1, n2);

    // If both sides return non-NULL
    if (left != NULL && right != NULL)
        return root;

    return (left != NULL) ? left : right;
}

// Example usage
int main() {
    // Example tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4  5  6  7

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int n1 = 4, n2 = 5;

    struct Node* lca = LCA(root, n1, n2);

    if (lca != NULL)
        printf("LCA: %d\n", lca->data);
    else
        printf("LCA not found\n");

    return 0;
}