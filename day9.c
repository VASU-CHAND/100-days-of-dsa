#include <stdio.h>

int main() {
    int p, q;

    printf("Enter size of first array: ");
    scanf("%d", &p);

    int a[p];
    printf("Enter %d elements (sorted):\n", p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &q);

    int b[q];
    printf("Enter %d elements (sorted):\n", q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0;

    printf("Merged array:\n");

    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d ", a[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}