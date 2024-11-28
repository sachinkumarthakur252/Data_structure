//Print and store the sparse matrix using arrays (TIP: Row major order or column major order to store the non-zero elements into array.)
#include <stdio.h>

int main()
{
    int rows, cols;
    printf("Enter the row and column of the matrix: ");
    scanf("%d %d", &rows, &cols); // step:1 Rows aur columns input lena

    int matrix[rows][cols]; // step:2 Matrix declare karna

    printf("Enter the elements of matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]); // step:3 Matrix elements input lena
        }
    }

    // step:4 Non-zero elements count karna
    int nonZeroCount = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                nonZeroCount++; //step:5 Non-zero element milne par count badhana
            }
        }
    }

    // step:6 Non-zero elements ke liye arrays declare karna
    int rowIndex[nonZeroCount], colIndex[nonZeroCount], value[nonZeroCount];

    // step:7 Non-zero elements ko arrays mein store karna
    int k = 0; // Index for non-zero arrays
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                rowIndex[k] = i;         // Row index store karna
                colIndex[k] = j;         // Column index store karna
                value[k] = matrix[i][j]; // step:8 Value store karna
                k++;
            }
        }
    }

    // step:9 Sparse matrix ko print karna
    printf("\nSparse Matrix (Row, Column, Value):\n");
    for (int i = 0; i < nonZeroCount; i++)
    {
    
        printf("rowIndex[%d], colIndex[%d], value[%d] \n", rowIndex[i], colIndex[i], value[i]);
    }

    return 0;
}
