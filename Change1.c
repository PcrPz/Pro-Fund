#include <stdio.h>
int main(){
    int x, y,change;
    int i,j;
    int Bank[8] ={1000,500,100,50,20,10,5,1};
    int Many[8] ={0,0,0,0,0,0,0,0};

    printf("Welcome to Simple Change Program\n");
    printf("Please Enter Your Money\n");
    scanf("%d", &y);
    if (y<=0)
    {
        printf("Error");
    }
    printf("Please Enter Your Total Price\n");
    scanf("%d", &x);
    if (x<=0)
    {
        printf("Error");
    }
    
    change = y-x;
    for (i = 0; i < 8; i++)
    {
        Many[i] = change/ Bank[i];
        change %= Bank[i];
    }
    for ( i = 0; i < 8; i++)
    {
        if  (Many[i] == 0)
       {
        continue;
       }
       printf("%d baht = %d \n",Bank[i],Many[i]);
    }
    return 0;
}