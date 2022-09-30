// WAP to add two matrices
#include <stdio.h>
void main()
{
    int A[10][10],B[10][10],C[10][10],r,c;
    printf("Enter number of rows and columns: ");
    scanf("%d %d",&r,&c);
    printf("Enter matrix 1 elements: ");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            scanf("%d",&A[i][j]);
    }
    printf("Enter matrix 2 elements: ");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            scanf("%d",&B[i][j]);
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            C[i][j]=A[i][j]+B[i][j];
    }
    printf("Addition of both matrices is: \n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            printf("%d\t",C[i][j]);
        printf("\n");
    }
}