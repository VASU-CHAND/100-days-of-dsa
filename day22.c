#include <stdio.h>

int main() {
    int m, n;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[100][100];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int isToeplitz = 1;   

    for(int i = 0; i < m - 1; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(matrix[i][j] != matrix[i+1][j+1]) {
                isToeplitz = 0;
                break;
            }
        }
        if(isToeplitz == 0)
            break;
    }

    if(isToeplitz)
        printf("Toeplitz Matrix\n");
    else
        printf("Not a Toeplitz Matrix\n");

    return 0;
}