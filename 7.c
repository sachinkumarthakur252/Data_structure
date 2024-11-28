// Program to copy elements of one array to another array in reverse order.
#include <stdio.h>

int main()
{
    // Step 1: Ek array ko kuch elements se initialize karna
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]); // Array ka size calculate karna

    // Step 2: Ek doosra array banate hain jisme reverse order mein elements copy karenge
    int revArr[n];

    // Step 3: Elements ko reverse order mein copy karna
    for (int i = 0; i < n; i++)
    {
        revArr[i] = arr[n - i - 1]; // Last element se shuru karke copy karna
    }

    // Step 4: Original array ko print karna
    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Step 5: Reversed array ko print karna
    printf("Reversed array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", revArr[i]);
    }
    printf("\n");

    return 0;
}
