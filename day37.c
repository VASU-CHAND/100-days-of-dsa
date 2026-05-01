#include <stdio.h>
#include <stdlib.h>

// compare function for qsort
int compare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;

    return x - y;   // ascending order
}

int main()
{
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Invalid size\n");
        return 0;
    }

    int arr[1000];   // fixed size to avoid VLA problem

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // sorting array
    qsort(arr, n, sizeof(int), compare);

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}