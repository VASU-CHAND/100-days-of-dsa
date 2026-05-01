#include <stdio.h>

int main() {
    int n;
    int sum = 0, expectedSum;

    
    scanf("%d", &n);

    int arr[n - 1];

    
    for(int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    
    expectedSum = n * (n + 1) / 2;

    
    printf("%d", expectedSum - sum);

    return 0;
}