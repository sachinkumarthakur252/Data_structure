//Program to merge two arrays into one using a function?
#include <stdio.h>

// Function to merge two arrays
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int mergedArray[])
{
    // Pehle array ke elements ko copy karenge
    for (int i = 0; i < size1; i++)
    {
        mergedArray[i] = arr1[i];
    }

    // Doosre array ke elements ko copy karenge
    for (int i = 0; i < size2; i++)
    {
        mergedArray[size1 + i] = arr2[i];
    }
}

int main()
{
    // Step 1: Do arrays ko define karte hain
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};

    // Step 2: Dono arrays ka size calculate karte hain
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Step 3: Merged array banate hain
    int mergedArray[size1 + size2];

    // Step 5: Function ko call karte hain aur merge karte hain
    mergeArrays(arr1, size1, arr2, size2, mergedArray);

    // Step 6: Merged array ko print karte hain
    printf("Merged Array: ");
    for (int i = 0; i < size1 + size2; i++)
    {
        printf("%d \t", mergedArray[i]);
    }

    return 0;
}