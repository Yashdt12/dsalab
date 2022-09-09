//WAP to input data into array and read out data from array
#include <stdio.h>
void main()
{
    int arr[100],size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    printf("Enter array elemets: ");
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("Array elements are: ");
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}