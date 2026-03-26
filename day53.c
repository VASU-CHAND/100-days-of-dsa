#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create Node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Vertical Order Function
void verticalOrder(struct Node* root) {

    if (root == NULL) return;

    struct Node* queue[MAX];
    int hd[MAX];          // horizontal distance
    int front = 0, rear = 0;

    int store[200][50];   // store vertical nodes
    int count[200] = {0};

    int offset = 100;     // to handle negative index

    queue[rear] = root;
    hd[rear] = 0;
    rear++;

    while (front < rear) {

        struct Node* temp = queue[front];
        int h = hd[front];
        front++;

        store[h + offset][count[h + offset]++] = temp->data;

        if (temp->left) {
            queue[rear] = temp->left;
            hd[rear] = h - 1;
            rear++;
        }

        if (temp->right) {
            queue[rear] = temp->right;
            hd[rear] = h + 1;
            rear++;
        }
    }

    // print vertical order
    for (int i = 0; i < 200; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", store[i][j]);
            }
            printf("\n");
        }
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

    verticalOrder(root);

    return 0;
}