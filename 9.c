//Program to check whether a given matrix is upper triangular matrix or lower triangular matrix.

#include <stdio.h>
int main()
{
    int i, j;
    int c = 0, p = 0;//step:1 c aur p dono counter hai jinki value abhi zero hai
    int arr[3][3], b[3][3];//row and column ko initialize kiya hai

    printf("Enter the value: \n");
    //step:2 user se value input lene ke liye
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
            if (j > i - 1 && arr[i][j] != 0)//step:3 upper triangular ke element ko check kiya ja raha hai
            {
                c++;//agar aisa hoga to "c" counter badhega
                
            }
            if (i > j - 1 && arr[i][j] != 0)//step:4 lower triangular ke element ko check kiya ja raha hai
            {
                p++;//agar aisa hoga to "p" counter badhega
            }
            
        }
    }

    printf("%d \n", c);
    if (c > 5 && p > 5)
    {
        printf("Not a sparsh matrix\n");
    }
    else
    {
        if (p > 5)
        {
            printf("This is lower triangular Sparsh matrix");
        }
        if (c > 5)
        {

            printf("This is upper triangular sparse matrix");
        }

        return 0;
    }
}