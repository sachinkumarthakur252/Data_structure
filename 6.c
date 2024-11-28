//Write a program to check whether a given matrix is sparse matrix or not.

#include <stdio.h>

int main()
{
    int matrix[4][4]; // Matrix declare karna
    int rows, cols;

    printf("Enter the number of row and column: ");
    scanf("%d %d", &rows, &cols); // User se rows aur columns input lena

    printf("Enter the elements of matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]); // Matrix elements input lena
        }
    }

    // Zero count aur total elements
    int zeroCount = 0;
    int totalElements = rows * cols;

    // Matrix check karna
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                zeroCount++; // Zero count badhana
            }
        }
    }

    // Sparse matrix ka check
    if (zeroCount > totalElements / 2)
    {
        printf("This matrix is a sparse matrix.");
    }
    else
    {
        printf("This matrix is not a sparse matrix.");
    }

    return 0;
}
