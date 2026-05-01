#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    printf("Enter a string: ");
    scanf("%99s", s);   

    int len = strlen(s);

    for (int i = len - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }

    printf("\n");
    return 0;
}
