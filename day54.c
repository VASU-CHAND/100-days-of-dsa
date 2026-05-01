#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char x) {
    if(x == '^')
        return 3;
    else if(x == '*' || x == '/')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    else
        return 0;
}

int main() {
    char infix[100], postfix[100];
    int i = 0, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while(infix[i] != '\0') {
        
        if(isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        else {
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }

        i++;
    }

    while(top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s", postfix);

    return 0;
}