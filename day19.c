#include <stdio.h>

int main() {
    char s[100];
    int left = 0, right = 0;
    int isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%99s", s);   

    while (s[right] != '\0') {
        right++;
    }
    right--;

    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
