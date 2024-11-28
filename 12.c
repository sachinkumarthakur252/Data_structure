//WAP to search an element in an array using binary search.
#include <stdio.h>
int main()
{
    int lb = 0, ub, mid = 0, value, n, i;
    printf("\nEnter numbers of array:\n"); // user inter the size of array
    scanf("%d", &n);
    int a[n];

    printf("\nEnter elements in array:\n"); // inserting element in array
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nEnter element which you want to search:\n"); // searching value
    scanf("%d", &value);
    
    ub = n - 1;
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (a[mid] < value)
        {
            lb = mid + 1;
        }
        else if (a[mid] == value)
        {
            printf("\n%d Found at location %d:\n", value, mid);
            break;
        }
        else
        {
            ub = mid - 1;
        }
    }
    if (lb > ub)
    {
        printf("\n %d is not found:\n", value);
    }

    return 0;
}
