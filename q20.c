// WAP to calculate row sum and column sum of a matrix
#include <stdio.h>
void main()
{
    int A[10][10],r,c,rsum[10],csum[10];
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
        rsum[i]=0;
        for(int j=0;j<c;j++)
            rsum[i]+=A[i][j];
    }
    for(int j=0;j<c;j++)
    {
        csum[j]=0;
        for(int i=0;i<r;i++)
            csum[j]+=A[i][j];
    }
    printf("Matrix along with row sum and column sum is:\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            printf("%d  ",A[i][j]);
        printf("\t%d\n",rsum[i]);
    }
    printf("\n");
    for(int i=0;i<c;i++)
        printf("%d  ",csum[i]);
    printf("\n");   
}