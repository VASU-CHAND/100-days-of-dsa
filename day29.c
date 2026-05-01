#include <stdio.h>

int main() {
    int m, n;
    int matrix[100][100];
    int sum = 0;
    
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    if (m <= 0 || n <= 0 || m > 100 || n > 100) {
        printf("Invalid matrix size\n");
        return 0;
    }

    printf("Enter matrix elements:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (m != n) {
        printf("Primary diagonal is defined only for square matrix.\n");
        return 0;
    }

    for(int i = 0; i < m; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of primary diagonal = %d\n", sum);

    return 0;
}
