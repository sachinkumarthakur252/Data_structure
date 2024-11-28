//Program to build and check for tri-diagonal matrix.
#include<stdio.h>


int main() {
    int n;
    printf("Enter the size of matrix (n*n): ");
    scanf("%d", &n); // Matrix ka size input lena (n x n matrix)

    int matrix[n][n];  // Matrix declare karna

    // Matrix ke elements input lena
    printf("Enter the elements of matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d",& matrix[i][j]);  // Matrix elements input karna
        }
    }

    // Check karna ki matrix tri-diagonal hai ya nahi
    int isTriDiagonal = 1;  // Assume initially matrix tri-diagonal hai (1 = true)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Diagonal, upper diagonal aur lower diagonal ke alawa elements 0 hone chahiye
            if (i != j && i != j + 1 && i != j - 1) {
                if (matrix[i][j] != 0) {
                    isTriDiagonal = 0;  // Agar element non-zero hai, toh matrix tri-diagonal nahi hai (0 = false)
                    break;
                }
            }
        }
        if (isTriDiagonal == 0) break;  // Agar ek bhi violation milta hai, toh loop exit karo
    }

    // Result print karna
    if (isTriDiagonal == 1) {
        printf("This matrix is a tri-diagonal matrix.\n");
    } else {
        printf("This matrix is not a tri-diagonal matrix.\n");
    }

    return 0;
}
