//WAP to reverse array elements using one array only
#include <stdio.h>
void main()
{
    int arr[100],size,temp;
    printf("Enter size of array: ");
    scanf("%d",&size);
    printf("Enter array elements: ");
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<size/2;i++)
    {
        temp=arr[i];
        arr[i]=arr[size-i-1];
        arr[size-i-1]=temp;
    }
    printf("Array elements after reversing are: ");
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}