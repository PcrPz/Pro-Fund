#include<stdio.h>
int ga = 10, gb = 20;
int f1(int a, int b) { a = a * 2; b = b * 3; ga = ga + 1; return a + b; }
int f2(int* a, int* b) { *a = *a + 3; *b = *b + 1; gb = gb + 2; return *a + *b; }
int f3(int a, int* b) { a = a + 5; *b = *b + 1; ga += gb; return a + *b; }
        7      10        a=12          gb 11      ga = 7+11     lb= 12+11=23
int main()
{
 int la = 1, lb = 2;
 printf("A: %d %d %d %d\n", ga, gb, la,lb); // 10 20 100 200
 gb = f1(la, lb);
 printf("B: %d %d %d %d\n", ga, gb, la, lb); // 11 20 1 80
 //ga =11 gb=8 la=1  lb=2
 ga = f2(&la, &lb);
 printf("C: %d %d %d %d\n", ga, gb, la, lb); //   7   10   4  3
 lb = f3(ga, &gb);
 printf("D: %d %d %d %d\n", ga, gb, la, lb); // 18 11 4 23
 return 0;
}