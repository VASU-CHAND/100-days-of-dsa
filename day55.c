#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    int val = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return val;
}

int evaluate(char exp[]) {
    int i = 0;

    while(exp[i] != '\0') {

        if(isdigit(exp[i])) {
            push(exp[i] - '0');
        }
        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/') {

            int b = pop();
            int a = pop();

            switch(exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
        i++;
    }

    return pop();
}

int main() {

    char exp[] = "231*+9-";

    printf("Result = %d", evaluate(exp));

    return 0;
}