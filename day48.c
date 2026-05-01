#include <stdio.h>

int main() {
    int n, m;

    scanf("%d", &n);
    int arr1[1000];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);

    scanf("%d", &m);
    int arr2[1000];

    for(int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);

    int i = n - 1;
    int j = m - 1;

    int intersection = -1;

    while(i >= 0 && j >= 0 && arr1[i] == arr2[j]) {
        intersection = arr1[i];
        i--;
        j--;
    }

    if(intersection != -1)
        printf("%d", intersection);
    else
        printf("No Intersection");

    return 0;
}