#include <stdio.h>
int main()
{
    int x, y, z;
    printf("Insert Number : ");
    scanf("%d", &x);
    for (y = 2; y <= x; y++)
    {
        if (x % y == 0)
        {
            if (y == x)
            {
                printf("Prime Number");
        
            }
            else
            {
                printf("Not Prime Number");
                break;
            }
        }
    }

    return 0;
}