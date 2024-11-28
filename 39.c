// Write a c program to search an element in array using Linear search.

#include <stdio.h>
int main()
{
    int a[50], n, i, location = 0, item;
    printf("\nEnter the size of Array :\n");
    scanf("%d", &n);

    printf("\nEnter elements in array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nEnter element which you want to search:\n");
    scanf("%d", &item);

    printf("\n Your linear search:\n");
    for (i = 0; i < n; i++)
    {
        if (a[i] == item)
        {
            location = i + 1;
            break;
        }
    }
    if (location > 0)
    {
        printf("\nItem found at %d position", location);
    }
    else
    {
        printf("\n Search unseccessful");
    }
    return 0;
}