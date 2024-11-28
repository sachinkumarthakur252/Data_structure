//Program to Calculate the sum of elements on the diagonals of an upper or lower triangular matrix.

#include <stdio.h>
int main()
{
    int i, j, sum1 = 0, sum2 = 0;
    int c = 0, p = 0;       // step:1 c aur p dono counter hai jinki value abhi zero hai
    int arr[3][3], b[3][3]; // row and column ko initialize kiya hai

    printf("Enter the value: \n");
    // step:2 user se value input lene ke liye
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("\n Value of [%d] [%d]= ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Now checking the matrix\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j > i - 1 && arr[i][j] != 0) // step:3 upper triangular ke element ko check kiya ja raha hai
            {
                c++; // agar aisa hoga to "c" counter badhega
                sum1 = sum1 + arr[i][j];
            }
            if (i > j - 1 && arr[i][j] != 0) // step:4 lower triangular ke element ko check kiya ja raha hai
            {
                p++; // agar aisa hoga to "p" counter badhega
                sum2 = sum2 + arr[i][j];
            }
        }
    }
    if (c > 5 && p > 5)

        printf("Not a sparsh matrix\n");
    
    else
    {
        if (p > 5)
        {
            printf("This is lower triangular Sparsh matrix \n");
            printf("The sum of lower tringular sparsh matrix is: %d", sum2);
        }
        if (c > 5)
        {

            printf("This is upper triangular sparse matrix \n");
            printf("The sum of upper triangular sparsh matrix is: %d", sum1);
        }

        return 0;
    }
}