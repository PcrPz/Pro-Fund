#include <stdio.h>
int main()
{
    int x, j, i, n;
    printf("Insert Number :");
    scanf("%d", &x);
    for (i = 1; i <= x; i++)
    {
        n = (2 * x) - 1;
        for (j = 0; j < n; j++)
        {
            if (j < i || j >= n - i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (i = 1; i <= x - 1; i++)
    {
        n = (2 * x) - 1;
        for (j = 0; j < n; j++)
        {
            if (x-i>j || x-i>=n-j)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}