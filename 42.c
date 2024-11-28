//Write a c program to sort a list of N elements using selection sort algorithm.
 
#include<stdio.h>
int main()
{ 
    int a[20],i,n,j,temp;
    printf("\n Enter the size of array:\n");
    scanf("%d",&n);

         printf("\nEnter element in array:\n");     
         for(i=0; i<n; i++)
    { 
       
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++)
    {
     for(j=0; j<n; j++)
     {
        if(a[i]<a[j])
        { 
             temp=a[j];
             a[j]=a[i];
             a[i]=temp;
        }
     }
    }
    printf("\n Selection sort element is:\n");
    for(i=0; i<n; i++)
    { 
        printf("%d\t",a[i]);
    }
    return 0;

}