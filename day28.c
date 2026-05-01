#include <stdio.h>

void setZeroes(int matrix[100][100], int rows, int cols) {
    int rowMark[100] = {0};
    int colMark[100] = {0};

    // Step 1: Mark rows and columns that contain zero
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 0) {
                rowMark[i] = 1;
                colMark[j] = 1;
            }
        }
    }

    // Step 2: Set entire row and column to zero
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(rowMark[i] == 1 || colMark[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    int rows, cols;
    int matrix[100][100];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    setZeroes(matrix, rows, cols);

    printf("Result matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
