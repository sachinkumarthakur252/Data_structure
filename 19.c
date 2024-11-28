//Write a c program to find the Factorial of a given number using Recursion?
#include<stdio.h>
void factorial(int n)
{
    static int fact=1;
    if(n>0)
    {
        fact=fact*n;
        factorial(n-1);
    }
    else
    {
        printf("Factorial of the given number is %d",fact);
    }
}
int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    factorial(n);
    return 0;
}