#include <stdio.h>
#include <limits.h>

int maxSubarraySumCircular(int* nums, int numsSize) {
    int total_sum = 0;
    int curr_max = 0, max_sum = INT_MIN;
    int curr_min = 0, min_sum = INT_MAX;

    for(int i = 0; i < numsSize; i++) {
        int num = nums[i];

        // Kadane for max
        curr_max = (curr_max + num > num) ? curr_max + num : num;
        max_sum = (curr_max > max_sum) ? curr_max : max_sum;

        // Kadane for min
        curr_min = (curr_min + num < num) ? curr_min + num : num;
        min_sum = (curr_min < min_sum) ? curr_min : min_sum;

        total_sum += num;
    }

    if(max_sum < 0)
        return max_sum;

    return (max_sum > total_sum - min_sum) ? max_sum : total_sum - min_sum;
}

int main() {
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxSubarraySumCircular(arr, n);

    printf("Maximum Circular Subarray Sum = %d", result);

    return 0;
}
