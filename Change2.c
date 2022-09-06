#include <stdio.h>
int main()
{
    int x, y, change;
    printf("Welcome to Simple Change Program\n");
    printf("Please Enter Your Money\n");
    scanf("%d", &y);
    printf("Please Enter Your Total Price\n");
    scanf("%d", &x);
    if (x >= 0 && y >= 0)
    {
        if (x > y)
        {
            printf("Not Enough Money");
        }
        else
        {
            change = y - x;
            printf("Your Change is %d\n", change);
            //--------------------------------------
            if (change >= 1000)
            {
                printf("1000 baht=%d\n", change / 1000);
                change = change % 1000;
            }
            if (change >= 500)
            {
                printf("500 baht=%d\n", change / 500);
                change = change % 500;
            }
            if (change >= 100)
            {
                printf("100 baht=%d\n", change / 100);
                change = change % 100;
            }
            if (change >= 50)
            {
                printf("50 baht=%d\n", change / 50);
                change = change % 50;
            }
            if (change >= 20)
            {
                printf("20 baht=%d\n", change / 20);
                change = change % 20;
            }
            if (change >= 10)
            {
                printf("10 baht=%d\n", change / 10);
                change = change % 10;
            }
            if (change >= 5)
            {
                printf("5 baht=%d\n", change / 5);
                change = change % 5;
            }
            if (change >= 2)
            {
                printf("2 baht=%d\n", change / 2);
                change = change % 2;
            }
            if (change >= 1)
            {
                printf("1 baht=%d\n", change / 1);
                change = change % 1;
            }
        }
    }
    else
    {
        printf("Please Try Again");
    }

    return 0;
}