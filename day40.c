#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {

    int n;
    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    for(int i = 0; i < n; i++) {

        int value;
        scanf("%d", &value);

        struct Node* newNode = malloc(sizeof(struct Node));

        if(newNode == NULL) {
            printf("Memory allocation failed\n");
            return 0;
        }

        newNode->data = value;
        newNode->next = NULL;   // VERY IMPORTANT

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Traversal with safety counter
    struct Node* temp = head;
    int count = 0;

    while(temp != NULL && count < n) {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }

    return 0;
}