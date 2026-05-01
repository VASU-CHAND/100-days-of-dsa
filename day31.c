#include <stdio.h>

int main() {
    int n;
    int arr[100];
    
    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++) {
        int count = 1;

        if(arr[i] == -1)
            continue;

        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = -1;   
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}