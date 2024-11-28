//Write a c program to sort a list of elements using Bubble Sort.

#include <stdio.h>
int main()
{
    int i, j, a[10], n, temp;
    printf("enter the number of element :\n");
    scanf("%d", &n);
    printf("enter the array element :\n");
    for (j = 0; j < n; j++)
        scanf("%d", &a[j]);
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n - j - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
    printf("\n the sorted elements are \n");
    for (j = 0; j < n; j++)
        printf("\t%d", a[j]);
    return 0;
}
