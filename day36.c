#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    result[0] = 1;
    for(int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }
    
    int rightProduct = 1;
    for(int i = numsSize - 1; i >= 0; i--) {
        result[i] = result[i] * rightProduct;
        rightProduct *= nums[i];
    }
    
    return result;
}

int main() {
    int n;
    
    printf("Enter size: ");
    scanf("%d", &n);
    
    int nums[1000];
    
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    int returnSize;
    int* result = productExceptSelf(nums, n, &returnSize);
    
    printf("Output:\n");
    for(int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    
    free(result);  // free allocated memory
    
    return 0;
}
