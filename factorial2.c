#include <stdio.h>
int main()
{
    int i, x, fac=1;
    printf("Enter Integer :");
    scanf("%d", &x);

    for (i = 0; i <x; i++)
    {
        fac *= (x - i);
    }
    printf("%d", fac);

    return 0;
}