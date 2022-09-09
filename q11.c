//WAP to add array elements and store the result in third array
#include <stdio.h>
void main()
{
    int a[100],b[100],c[100],size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    printf("Enter array 1 elemets: ");
    for(int i=0;i<size;i++)
        scanf("%d",&a[i]);
    printf("Enter array 2 elemets: ");
    for(int i=0;i<size;i++)
        scanf("%d",&b[i]);
    for(int i=0;i<size;i++)
        c[i]=a[i]+b[i];
    printf("Sum of corresponding elements: ");
    for(int i=0;i<size;i++)
        printf("%d ",c[i]);
    printf("\n");
}