#include <stdio.h>
#include <string.h>
int main()
{
    int i;
    char *p, str[50];
    p = str;
    scanf("%s", str);
    while (*p != '\0')
    {

        if (*p >= 'a' && *p <= 'z')
        {
            *p = *p - ' ';
            printf("%c", *p);
        }
        else if (*p >= 'A' && *p <= 'Z')
        {
            *p = *p + ' ';
            printf("%c", *p);
        }
        else
        {
        }
        p++;
    }
    return 0;
}