//Program to find the transpose of a 2D array

#include <stdio.h>
int main()
{
    int a[3][3], i, j;
    // ensert elements in array
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("\nEnter value of a[%d][%d]:", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    // printing original matrix
    printf("\n Matrix is:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    // printing transpose matrix
    printf("\n Transpose of matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", a[j][i]);
        }
        printf("\n");
    }
    return 0;
}