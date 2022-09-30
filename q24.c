// WAP to exhange two rows and two columns of a matrix
#include <stdio.h>
void main()
{
    int A[10][10],r,c,p,q,temp;
    printf("Enter number of rows and columns: ");
    scanf("%d %d",&r,&c);
    printf("Enter matrix elements: ");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            scanf("%d",&A[i][j]);
    }
    printf("Enter two rows that you want to interchange: ");
    scanf("%d %d",&p,&q);
    for(int i=0;i<c;i++)
    {
        temp=A[p-1][i];
        A[p-1][i]=A[q-1][i];
        A[q-1][i]=temp;
    }
    printf("Matrix after interchanging rows is:\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            printf("%d\t",A[i][j]);
        printf("\n");
    }
    printf("Enter two columns that you want to interchange: ");
    scanf("%d %d",&p,&q);
    for(int i=0;i<r;i++)
    {
        temp=A[i][p-1];
        A[i][p-1]=A[i][q-1];
        A[i][q-1]=temp;
    }
    printf("Matrix after interchanging columns is:\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            printf("%d\t",A[i][j]);
        printf("\n");
    }
}