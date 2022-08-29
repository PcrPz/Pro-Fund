#include <stdio.h>
int main()
{
    int sum = 1, x, i;
    printf("Factorial Program\n");
    printf("Enter Integer :");
    scanf("%d", &x);
    
    if (x != 0)
    {
        for (i = 1; i <= x; i++)
        {
            sum = sum*i;
        }
        printf("%d",sum);
    }
    else
    {
        sum = 1;
        printf("%d", sum);
    }

    return 0;
}
