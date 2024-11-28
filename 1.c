// Program to initialize an array and print its elements using a function?
#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // Initialize an array
    int myArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(myArray) / sizeof(myArray[0]); // Calculate the size of the array

    // Call the function to print the array elements
    printArray(myArray, size);

    return 0;
}