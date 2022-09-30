// WAP to check if a matrix is symmetric or not
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
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(A[i][j] != A[j][i])
            {
                printf("Matrix is not symmetric\n");
                return;
            }
        }
    }
    printf("Matrix is symmetric\n");
}