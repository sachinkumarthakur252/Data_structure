//WAP to merge two sorted array of same size in descending order.

#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size); // Arrays ki size input lena

    int arr1[size], arr2[size], merged[2 * size]; // Do arrays aur ek merged array declare karna

    printf("Enter the first sorted array element:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr1[i]); // First array ke elements input lena
    }

    printf("Enter the second sorted array element:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr2[i]); // Second array ke elements input lena
    }

    // First array ke elements ko merge array mein daalna
    for (int i = 0; i < size; i++)
    {
        merged[i] = arr1[i];
    }

    // Second array ke elements ko merge array mein daalna
    for (int i = 0; i < size; i++)
    {
        merged[size + i] = arr2[i];
    }

    // Descending order mein sort karna
    for (int i = 0; i < 2 * size - 1; i++)
    {
        for (int j = 0; j < 2 * size - 1 - i; j++)
        {
            if (merged[j] < merged[j + 1])
            {
                // Swap karna agar next element bada ho
                int temp = merged[j];
                merged[j] = merged[j + 1];
                merged[j + 1] = temp;
            }
        }
    }

    // Merged array ko print karna
    printf("Merged array in descending order:\n");
    for (int i = 0; i < 2 * size; i++)
    {
        printf("%d \t", merged[i]);
    }

    return 0;
}
