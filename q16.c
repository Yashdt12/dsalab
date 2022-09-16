//WAP to delete an array element from an array
#include <stdio.h>
void main()
{
    int arr[100],size,position;
    printf("Enter size of array: ");
    scanf("%d",&size);
    printf("Enter array elements: ");
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("Enter position to delete: ");
    scanf("%d",&position);
    if(position<1 || position>size)
    {
        printf("Invalid position\n");
        return;
    }
    for(int i=position;i<size;i++)
        arr[i-1]=arr[i];
    size--;
    printf("Array elements after deletion are: ");
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}