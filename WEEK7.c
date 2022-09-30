#include <stdio.h>
#include <string.h>
int main()
{
    int i, num, count;
    char lastmode, curmode;
    char str[100];
    scanf("%s", str);

    int LITmode = 0;
    int BIGmode = 0;
    
    for (i = 0; i < strlen(str); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') )
        {
            LITmode = 1;
        }
        if ( (str[i] >= 'A' && str[i] <= 'Z'))
        {
            BIGmode = 1;
        }
    }
    if (LITmode == 0 && BIGmode == 1)
    {
        printf("All Capital Letter");
    }
    else if (LITmode == 1 && BIGmode == 0)
    {
        printf("All Small Letter");
    }
    else(printf("Mix"));
    
    return 0;
}