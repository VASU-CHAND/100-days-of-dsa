#include <stdio.h>

void moveZeroes(int nums[], int numsSize) {
    int j = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            j++;
        }
    }
}

int main() {
    int numsSize;

    printf("Enter the number of elements: ");
    scanf("%d", &numsSize);

    int nums[numsSize];

    printf("Enter the elements:\n");
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    moveZeroes(nums, numsSize);

    printf("Array after moving zeroes:\n");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}