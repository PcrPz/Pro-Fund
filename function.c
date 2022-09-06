#include <stdio.h>
int isprime(int x)
{
    int y, a = 0;
    for (y = 1; y <= x; y++)
    {
        if (x % y == 0)
        {
            a++;
        }
    }
    if (a == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int x, y, a, sol;
    scanf("%d", &x);
    sol = isprime(x);
    if (sol == 1)
    {
        printf(" Prime Number");
    }
    else
    {
        printf(" Not Prime Number");
    }

    return 0;
}
