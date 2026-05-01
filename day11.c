#include <stdio.h>

int main() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements (sorted):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unique elements are: ");
    printf("%d ", arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}