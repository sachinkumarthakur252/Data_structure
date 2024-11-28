//Write a program to insert the element at nth position in an array.
#include <stdio.h>
int main()

{
    int a[50];//step:1 array ka maximum size set kiya gaya hai
    int i, size, pos, value;
    printf("Enter the size of array: \n");
    scanf("%d", &size);//step:2 array ka size user se input liya ja raha hai
    if (size > 50)
    {

        printf("You entered invalid array size!");
    }
    else
    {
        printf("Enter element in array:\n");//step:3 ab array ka elements user se liya ja rah hai
        for (i = 0; i < size; i++)
        {
            scanf("%d", &a[i]);
        }

        printf("select position:\n");//step:4 new element insert ke liye user se position liya ja raha hai
        scanf("%d", &pos);
        if (pos <= 0 || pos > size)
        {
            printf("Invalid position!\n");
        }
        else
        {
            printf("Enter the value which you want to insert:\n");//step:5 user se inserting value insert ke liye
            scanf("%d", &value);

            for (i = size - 1; i >= pos - 1; i--)
            {
                a[i + 1] = a[i];
            }
            a[pos - 1] = value;
            size++;

            printf("Array element after insertion:\n");//step:6 insert ke baat array ko print kiya ja raha hai
            
            for (i = 0; i < size; i++)
            {
                printf("%d \n", a[i]);
            }
        }
    }
}