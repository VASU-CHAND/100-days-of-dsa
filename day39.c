 #include <stdio.h>
#include <stdlib.h>

#define MAX 200001
#define OFFSET 100000

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix_sum = 0;
    int count = 0;

    int hash[MAX] = {0};

    hash[OFFSET] = 1;   // prefix_sum = 0

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if(prefix_sum + OFFSET >= 0 && prefix_sum + OFFSET < MAX) {
            count += hash[prefix_sum + OFFSET];
            hash[prefix_sum + OFFSET]++;
        }
    }

    printf("%d\n", count);

    free(arr);
    return 0;
}