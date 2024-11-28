//Program to check if an array is sorted in ascending or descending order using a function.
#include <stdio.h>

int isAscending(int arr[], int size);  // Function declaration
int isDescending(int arr[], int size); // Function declaration

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n); // Array ka size input lena

    int arr[n]; // Array declare karna

    printf("Enter the elements in array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); // Array elements input lena
    }

    // Ascending ya descending order check karna
    if (isAscending(arr, n) == 1)
    {
        printf("The array is sorted in ascending order.\n");
    }
    else if (isDescending(arr, n) == 1)
    {
        printf("The array is sorted in descending order.\n");
    }
    else
    {
        printf("Array is not sorted.\n");
    }

    return 0;
}

// Function to check if array is in ascending order
int isAscending(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0; // Agar koi element next se bada hai toh ascending nahi hai
        }
    }
    return 1; // Agar sab elements ascending hain
}

// Function to check if array is in descending order
int isDescending(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            return 0; // Agar koi element next se chhota hai toh descending nahi hai
        }
    }
    return 1; // Agar sab elements descending hain
}