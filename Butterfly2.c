#include <stdio.h>
int main()
{
    int i, j, x, n;
    int l = 0;
    scanf("%d", &x);
    n = (2 * x) - 1;
    int r = n - 1;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j <= l || j >= r)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        l++;
        r--;
        printf("\n");
    }
    for (i = 0; i < x-1; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j <= r || j >= l)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        l++;
        r--;
        printf("\n");
    }
}