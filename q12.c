//WAP to display an array in reverse order
#include <stdio.h>
void main()
{
    int arr[100],size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    printf("Enter array elements: ");
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("Array elements in reverse order are: ");
    for(int i=size-1;i>=0;i--)
        printf("%d ",arr[i]);
    printf("\n");
}