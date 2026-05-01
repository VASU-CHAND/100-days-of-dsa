#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Delete first occurrence of key
struct Node* deleteFirst(struct Node* head, int key) {
    struct Node *temp = head, *prev = NULL;

    // If head contains key
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL)
        return head;

    prev->next = temp->next;
    free(temp);

    return head;
}

int main() {
    int n, key;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    // Create linked list
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &key);

    head = deleteFirst(head, key);

    // Print result
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}