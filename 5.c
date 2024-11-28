//Program to perform multiplication of two 2D arrays on 3x3 matrix and store the result in another matrix.
#include<stdio.h>
int main()
{ 
    int a[3][3], b[3][3], c[3][3], i, j,k;
    printf("\n Enter the value of 'a' matrix:");
    for(i=0; i<3; i++)
        { 
            for(j=0; j<3;j++)
                { 
                    printf("\n Value of [%d] [%d]= ",i,j);
                    scanf("%d",&a[i][j]);
                }
        }
    printf("\n Enter the value of 'b' matrix:");
    for(i=0; i<3; i++)
        { 
            for(j=0; j<3;j++)
                { 
                    printf("\n Value of [%d] [%d]= ",i,j);
                    scanf("%d",&b[i][j]);
                }
        }
    for(i=0; i<3; i++)
        { 
            for(j=0; j<3; j++)
                { 
                    int sum=0;
                    for(k=0; k<3; k++)
                        { 
                            sum=sum+a[i][k]*b[k][j];
                        }
                            c[i][j]=sum;
                }
        }
        printf("\n Multiply is:\n");
    for(i=0; i<3; i++)
        { 
            for(j=0; j<3; j++)
                { 
                    printf("%d\t",c[i][j]);
                }
                    printf("\n");
        }
    return 0;
}