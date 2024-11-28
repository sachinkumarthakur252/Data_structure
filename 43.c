//Write a c program to sort N elements using Insertion sort. 
#include <stdio.h>
int main()
{
    int a[100], n, j, k, pass;
    printf("enter the number of element :\n");
    scanf("%d", &n);
    printf("enter the array element :\n");
    for (j = 0; j < n; j++)
        scanf("%d", &a[j]);
    for (pass = 1; pass < n; pass++)
    {
        k = a[pass];
        for (j = pass - 1; j >= 0 && k < a[j]; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = k;
    }
    printf("the sorted array elements \n");
    for (j = 0; j < n; j++)
        printf("%d\t", a[j]);
    return 0;
}
