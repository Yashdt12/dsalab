// WAP to perform matrix multiplication
#include <stdio.h>
void main()
{
    int A[10][10],B[10][10],C[10][10],r1,c1,r2,c2;
    printf("Enter number of rows and columns of matrix 1: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter matrix 1 elements: ");
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
            scanf("%d",&A[i][j]);
    }
    printf("Enter number of rows and columns of matrix 2: ");
    scanf("%d %d",&r2,&c2);
    printf("Enter matrix 2 elements: ");
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
            scanf("%d",&B[i][j]);
    }
    if(c1 != r2)
    {
        printf("Multiplication not possible\n");
        return;
    }
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            C[i][j]=0;
            for(int k=0;k<c1;k++)
                C[i][j]+=A[i][k]*B[k][j];
        }
    }
    printf("Product of both matrices is: \n");
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
            printf("%d\t",C[i][j]);
        printf("\n");
    }
}