#include <stdio.h>

#define SIZE 7

int table[SIZE];

void init() {
    for(int i = 0; i < SIZE; i++)
        table[i] = -1;
}

void insert(int key) {
    int index = key % SIZE;

    for(int i = 0; i < SIZE; i++) {
        int newIndex = (index + i*i) % SIZE;

        if(table[newIndex] == -1) {
            table[newIndex] = key;
            return;
        }
    }
    printf("Hash Table Full\n");
}

void search(int key) {
    int index = key % SIZE;

    for(int i = 0; i < SIZE; i++) {
        int newIndex = (index + i*i) % SIZE;

        if(table[newIndex] == -1) {
            printf("NOT FOUND\n");
            return;
        }

        if(table[newIndex] == key) {
            printf("FOUND\n");
            return;
        }
    }
    printf("NOT FOUND\n");
}

int main() {
    init();

    insert(49);
    insert(56);

    search(49);
    search(15);

    return 0;
}