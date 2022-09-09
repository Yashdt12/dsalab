//WAP to access array elements using array as a pointer
#include <stdio.h>
void main()
{
    int arr[]={1,2,3,4,5},size=5;
    for(int i=0;i<size;i++)
        printf("%d\t",*(arr+i));
    printf("\n");
}