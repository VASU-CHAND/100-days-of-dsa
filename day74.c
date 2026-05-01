#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue
struct Node* queue[MAX];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Zigzag Traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    enqueue(root);
    int leftToRight = 1;

    while (!isEmpty()) {
        int size = rear - front;
        int level[size];

        // store level nodes
        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue();

            level[i] = curr->data;

            if (curr->left) enqueue(curr->left);
            if (curr->right) enqueue(curr->right);
        }

        // print according to direction
        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", level[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        leftToRight = !leftToRight; // toggle
    }
}

// Main
int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

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