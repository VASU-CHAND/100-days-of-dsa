#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    int n;
    scanf("%d", &n);

    if(n <= 0) {
        return 0;
    }

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        // Allocate memory
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Forward Traversal
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}