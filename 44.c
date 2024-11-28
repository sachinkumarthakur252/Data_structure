//Write a C program to sort elements using Merge Sort.

#include <stdio.h>

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n]; // Temporary array for merging
    int left_start, left_end, right_start, right_end, i, j, k;

    // Perform merge sort
    for (int size = 1; size < n; size *= 2)
    {
        for (left_start = 0; left_start < n; left_start += 2 * size)
        {
            left_end = left_start + size - 1;
            right_start = left_start + size;
            right_end = right_start + size - 1;

            // Ensure we do not go out of bounds
            if (left_end >= n)
            {
                break;
            }
            if (right_start >= n)
            {
                right_start = n;
                right_end = n - 1;
            }
            else if (right_end >= n)
            {
                right_end = n - 1;
            }

            // Merge the two halves
            i = left_start;  // Starting index for left subarray
            j = right_start; // Starting index for right subarray
            k = left_start;  // Starting index to be sorted

            while (i <= left_end && j <= right_end)
            {
                if (arr[i] <= arr[j])
                {
                    temp[k++] = arr[i++];
                }
                else
                {
                    temp[k++] = arr[j++];
                }
            }

            // Copy remaining elements of left subarray, if any
            while (i <= left_end)
            {
                temp[k++] = arr[i++];
            }

            // Copy remaining elements of right subarray, if any
            while (j <= right_end)
            {
                temp[k++] = arr[j++];
            }

            // Copy the sorted subarray back into the original array
            for (i = left_start; i <= right_end; i++)
            {
                arr[i] = temp[i];
            }
        }
    }

    // Print sorted array
    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}