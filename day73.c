#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue node for BFS
struct QNode {
    struct Node* node;
    int hd;
};

// Queue
struct Queue {
    int front, rear;
    struct QNode arr[MAX];
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

// Dequeue
struct QNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    // Store values by HD
    int map[2000][100];  // rows = HD offset, cols = nodes
    int count[2000] = {0};

    int offset = 1000; // to handle negative HD

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root, 0);

    int minHD = 0, maxHD = 0;

    while (!isEmpty(&q)) {
        struct QNode temp = dequeue(&q);
        struct Node* node = temp.node;
        int hd = temp.hd;

        // Store node
        map[hd + offset][count[hd + offset]++] = node->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            enqueue(&q, node->left, hd - 1);
        if (node->right)
            enqueue(&q, node->right, hd + 1);
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < count[i + offset]; j++) {
            printf("%d ", map[i + offset][j]);
        }
        printf("\n");
    }
}

// Example Tree (same as your input)
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

    verticalOrder(root);

    return 0;
}