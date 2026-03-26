#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Zigzag Traversal Function
void zigzagTraversal(struct Node* root) {

    if (root == NULL) return;

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {

        int size = rear - front;
        int arr[size];

        // store current level
        for (int i = 0; i < size; i++) {

            struct Node* temp = queue[front++];

            arr[i] = temp->data;

            if (temp->left)
                queue[rear++] = temp->left;

            if (temp->right)
                queue[rear++] = temp->right;
        }

        // print level
        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", arr[i]);
        }
        else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", arr[i]);
        }

        leftToRight = !leftToRight;
    }
}

int main() {

    // Example Tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    zigzagTraversal(root);

    return 0;
}