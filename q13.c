//WAP to reverse the array elements
#include <stdio.h>
void main()
{
    int a[100],b[100],size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    printf("Enter array elements: ");
    for(int i=0;i<size;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<size;i++)
        b[i]=a[size-i-1];
    printf("Array elements after reversing are: ");
    for(int i=0;i<size;i++)
        printf("%d ",b[i]);
    printf("\n");
}