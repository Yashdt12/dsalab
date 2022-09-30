// WAP to exchange principal diagonal elements with secondary diagonal elements
#include <stdio.h>
void main()
{
    int A[10][10],r,c,temp;
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
            if(i==j)
            {
                temp=A[i][j];
                A[i][j]=A[i][c-i-1];
                A[i][c-i-1]=temp;
            }
        }
    }
    printf("Matrix after interchanging is: \n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            printf("%d\t",A[i][j]);
        printf("\n");
    }
}