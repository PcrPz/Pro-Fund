#include <stdio.h>
int main()
{  printf("Please Enter Number To Check :");
    int x, y, a;
    printf("Please Enter Number To Check :");
    scanf("%d", &x);

    for (y = 1; y <= x; y++)
    {
        if (x % y == 0)
        {
             a++;
        }
    }
    if (a == 2)
    {
        printf("Prime Number");
    }
    else
    {
        printf("Not Prime Number");
    }

    return 0;
}