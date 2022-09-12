#include <stdio.h>
#include <string.h>
//ใช้เป็นpointer
int main()
{
    char ans[100];
    printf("Enter the string to check if it is palindrome :");
    scanf("%s", ans);
    char *first;
    char *last;
    first=ans;
    while (*first != '\0') {
        first++;
    }
//เคลียให้เหลือตัวท้าย
    first--;
   for (last = ans; first >= last;) {
    
        if (*first == *last) {
            --first;
            last++;
        }
        else
            break;
    }
 
    if (last > first)
        printf("Palindrome");
    else
        printf("not a Palindrome");
}
 
