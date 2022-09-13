#include <stdio.h>
#include <string.h>
int main()
{
    char ans[100];
    printf("Enter the string to check if it is palindrome ");
    scanf("%s", ans);
    int strans = strlen(ans);
    int i, j = strans - 1;
    int z;

    for (i = 0; i < strans; i++, j--)
    {
        if ((ans[i]) != (ans[j]))
        {
            z = 0;
        }
        else
        {
            z = 1;
        }
    }
    if (z == 0)
    {
        printf("not a Palindrome");
    }
    else
    {
        printf("Palindrome");
    }

    return 0;}