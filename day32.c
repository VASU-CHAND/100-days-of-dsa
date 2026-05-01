#include <stdio.h>

int main() {
    int n, k;
    int arr[100], temp[100];

    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n <= 0) {
        printf("Invalid size");
        return 0;
    }

    // Input elements
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input k
    printf("Enter value of k: ");
    scanf("%d", &k);

    k = k % n;   // Handle large k values

    // Rotate array to right
    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    // Copy back
    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    // Print rotated array
    printf("Rotated array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
