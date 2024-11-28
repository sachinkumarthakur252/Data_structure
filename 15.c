//Write a c program to delete an element in the array.
#include <stdio.h>
int main()

{
    int a[50];//step:1 array ka maximum size set kiya gaya hai
    int i, size, pos, value;
    printf("Enter the size of array: \n");
    scanf("%d", &size);//step:2 size ko user se lene ke liye
    if (size > 50)
    {

        printf("You entered invalid array size!");
    }
    else
    {
        printf("Enter element in array:\n");//step:3 element user se input lene ke liye
        for (i = 0; i < size; i++)
        {
            scanf("%d", &a[i]);
        }

        printf("select position:\n");//step:4 select the position
        scanf("%d", &pos);
        if (pos <= 0 || pos > size)
        {
            printf("Invalid position!\n");
        }
        else
        {

            for(i=pos-1; i<=size-1; i++)
            {
                a[i]=a[i+1];
            }
            
            size--;

            printf("Array element after insertion:\n");//step:5 delete karne ke baad se array ko print kiya ja raha hai
            for (i = 0; i < size; i++)
            {
                printf("%d \n", a[i]);
            }
        }
    }
}