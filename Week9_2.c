// #include <stdio.h>
// int main()
// {
//     int sum = 0;
//     int s[3];
//     printf("This program spilt bread\n");
// 	printf("Enter your size of bread :");
//     for (int i = 0; i < 3; i++)
//         {
//     scanf("%d", &s[i]);}
//     int i;
//     while (s[0] != 1 && s[1] != 1 && s[2] != 1)
//     {
//         for (i = 0; i < 3; i++)
//         {
//             //ตัดส่วนเกินขนาดลูกบาศก์
//             if (s[i] % 2 != 0 )
//             {
//                 s[i] = s[i] - 1;
//             }
//             //เเบ่งปกติ
//             if (s[i] % 2 == 0 )
//             {
//                 s[i] = s[i] % 2;
//                 sum++;
//             }
//         }
//     }
// printf("cut %d times.", sum);
// return 0;
// }
#include <stdio.h>
int main()
{
	int s[3];
	int i, j, sum = 0;
	printf("This program spilt bread\n");
	printf("Enter your size of bread :");
    for ( j = 0; j < 3; j++)
    {
        scanf("%d", &s[j]);
    }
    
	
	while ( s[0] != 1 || s[1] != 1 || s[2] != 1 )
	{
		for ( i=0 ; i<3 ; i++)

		{   //ตัดส่วนเกินขนาดลูกบาศก์
			if ( s[i] % 2 !=0 && s[i] != 1)
			{
				s[i]--;
			}
            //เเบ่งปกติ
			if ( s[i] % 2 ==0 && s[i] != 1)
			{
				while ( s[i] != 1)
				{
					s[i] /= 2;
					sum++;
				}
			}
		}
	}
	printf("cut %d times.", sum);
	
	return 0;
}
