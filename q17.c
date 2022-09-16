//WAP to insert an element into a sorted array
#include <stdio.h>
void main()
{
    int arr[100],i,size,element,position;
    printf("Enter size of array: ");
    scanf("%d",&size);
    printf("Enter array elements in ascending order: ");
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("Enter element to be inserted: ");
    scanf("%d",&element);
    for(i=0;i<size;i++)
    {
        if(arr[i]>element)
            break;
    }
    position=i+1;
    for(int i=size-1;i>=position-1;i--)
        arr[i+1]=arr[i];
    arr[position-1]=element;
    size++;
    printf("Array elements after insertion are: ");
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}