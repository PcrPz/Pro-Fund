#include <stdio.h>
#include <string.h>
int LITstack;
int BIGstack;
void check(char *str)
{
    char *check;
    check = str;

    while (*check != '\0')
    {
        if (*check >= 97 && *check <= 122)
        {
            LITstack++;
        }
        if (*check >= 65 && *check <= 90)
        {
            BIGstack++;
        }
        check++;
    }
    if (LITstack == 0 && BIGstack > 0)
    {
        printf("All Capital Letter");
    }
    else if (LITstack > 0 && BIGstack == 0)
    {
        printf("All Small Letter");
    }
    else if (LITstack > 0 && BIGstack > 0)
    {
        printf("Mix");
    }
}

int main()
{
    char str[100];
    scanf("%s", str);
    check(str);
    return 0;
}
