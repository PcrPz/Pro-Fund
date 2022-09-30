#include <stdio.h>
int i, j;
int Max1[10][10];
int Max2[10][10];
int sum[10][10];
int row, col;
// ฟังกชันคำนวณ
void sum_print(int Max1[10][10], int Max2[10][10], int sum[10][10])
{

  for (i = 0; i < row; ++i)
  {
    for (j = 0; j < col; ++j)
    {
      sum[i][j] = Max1[i][j] + Max2[i][j];
    }
  }
  for (i = 0; i < row; ++i)
  {
    for (j = 0; j < col; ++j)
    {
      printf("%d ", sum[i][j]);
    }
    printf("\n");
  }
}

int main()
{
//ใส่จำนวนคอลัม*เเถว
  printf("Enter the number of rows: ");
  scanf("%d", &row);
  printf("Enter the number of columns : ");
  scanf("%d\n", &col);
//ใส่เมทริก 1
  printf("Matrix 1\n");
  for (i = 0; i < row; ++i)
  {
    for (j = 0; j < col; ++j)
    {
      printf("Enter Number in Matrix1[%d][%d]: ", i, j);
      scanf("%d", &Max1[i][j]);
    }
  }
//ใส่เมทริก 2
  printf("Matrix 2\n");
  for (i = 0; i < row; ++i)
  {
    for (j = 0; j < col; ++j)
    {
      printf("Enter Number in Matrix2[%d][%d]: ", i, j);
      scanf("%d", &Max2[i][j]);
    }
  }
  // ฟังกชันคำนวณ
  sum_print(Max1, Max2,sum);
  return 0;
}
