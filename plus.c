#include <stdio.h>
int main()
{
    int x,sum;
        printf("Insert Number:");
        scanf("%d",&x);
        sum=0;
        while(x>9){
            sum=0;
        while(x>0)
            {
            sum = sum + x%10;
            x=x/10;
            }
            x=sum;
        }
        printf("%d",x);

            return 0;
}