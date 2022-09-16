//WAP to insert an array element to an array at a given position
#include <stdio.h>
void main()
{
    int arr[100],size,position,element;
    printf("Enter size of array: ");
    scanf("%d",&size);
    printf("Enter array elements: ");
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("Enter element and position to be inserted: ");
    scanf("%d %d",&element,&position);
    if(position<0 || position>size+1)
    {
        printf("Invalid position\n");
        return;
    }
    for(int i=size-1;i>=position-1;i--)
        arr[i+1]=arr[i];
    arr[position-1]=element;
    size++;
    printf("Array elements after insertion are: ");
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}