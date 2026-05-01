#include <stdio.h>

int main()
{
    int n, i, j;
    
    printf("Enter size of matrix: ");
    scanf("%d", &n);

    int matrix[50][50];
    int isIdentity = 1;

    printf("Enter matrix elements:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j && matrix[i][j] != 1)
            {
                isIdentity = 0;
                break;
            }
            if(i != j && matrix[i][j] != 0)
            {
                isIdentity = 0;
                break;
            }
        }
    }

    if(isIdentity == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
