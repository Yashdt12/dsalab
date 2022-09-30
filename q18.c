// WAP to input matrix from user and print it
#include <stdio.h>
void main()
{
    int A[10][10],r,c;
    printf("Enter number of rows and columns: ");
    scanf("%d %d",&r,&c);
    printf("Enter matrix elements: ");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            scanf("%d",&A[i][j]);
    }
    printf("Matrix is: \n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            printf("%d\t",A[i][j]);
        printf("\n");
    }
}