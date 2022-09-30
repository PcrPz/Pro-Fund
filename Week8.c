#include <stdio.h>
int main()
{
    int Row;
    int Col;
    //ใส่จำนวนคอลัม*เเถว
    printf("Enter the number of rows: ");
    scanf("%d", &Row);
    printf("Enter the number of columns: ");
    scanf("%d", &Col);
    int matrix1[Row][Col];
    int matrix2[Row][Col];
    int sum[Row][Col];
    int i = 0;
    int j = 0;
    //ใส่เมทริก 1
    printf("Matrix 1\n");
    while (i < Row)
    {
        while (j < Col)
        {
            printf("Enter Number in Matrix1[%d][%d]: ", i+ 1, j+ 1);
            scanf("%d", (*(matrix1 + i) + j));
            j++;
        }
        i++;
        j = 0;
    }
    i = 0;
    j = 0;
    //ใส่เมทริก 2
    printf("Matrix 2\n");
    while (i < Row)
    {
        while (j < Col)
        {
            printf("Enter Number in Matrix2[%d][%d]: ", i+ 1, j+ 1);
            scanf("%d", (*(matrix2 + i) + j));
            j++;
        }
        i++;
        j = 0;
    }
    i = 0;
    j = 0;
    //คำนวณ
    printf("Matrix Sum\n");
    while (i < Row)
    {
        while (j < Col)
        {
            *(*(sum + i) + j) = *(*(matrix1 + i) + j) + *(*(matrix2 + i) + j);
            j++;
        }
        i++;
        j = 0;
    }
    i = 0;
    j = 0;
    //เเสดงผลออกมา
    while (i < Row)
    {
        while (j < Col)
        {
            printf("%d ", *(*(sum + i) + j));
            j++;
        }
        printf("\n");
        i++;
        j = 0;
    }

    return 0;
}