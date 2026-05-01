#include <stdio.h>

int main()
{
    int n, a = 0, b = 1, c;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n == 0)
        printf("Fibonacci number is: 0\n");
    else if (n == 1)
        printf("Fibonacci number is: 1\n");
    else
    {
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        printf("Fibonacci number is: %d\n", b);
    }

    return 0;
}