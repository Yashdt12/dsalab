// WAP to calculate trace and norm of a matrix
#include <stdio.h>
#include <math.h>
void main()
{
    int A[10][10],r,c,trace=0,sum=0;
    float norm;
    printf("Enter number of rows and columns: ");
    scanf("%d %d",&r,&c);
    printf("Enter matrix elements: ");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            scanf("%d",&A[i][j]);
    }
    for(int i=0;i<r;i++)
        trace+=A[i][i];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            sum+=A[i][j]*A[i][j];
    }
    norm=sqrt(sum);
    printf("Trace and norm of the matrix is: %d and %f\n",trace,norm);
}