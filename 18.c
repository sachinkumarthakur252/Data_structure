// Write a recursive program to find GCD of 4,6,8 ?
#include <stdio.h>

// Function to find GCD of two numbers using recursion
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

// Function to find GCD of an array of numbers
int gcd_of_array(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    return gcd(arr[n - 1], gcd_of_array(arr, n - 1));
}

int main()
{
    int arr[] = {4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = gcd_of_array(arr, n);
    printf("GCD of the array is: %d\n", result);

    return 0;
}