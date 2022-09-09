//WAP to find sum of all elements stored in array using pointer
#include <stdio.h>
void main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10},size=10,sum=0;
    for(int i=0;i<size;i++)
        sum+=*(arr+i);
    printf("Sum of all elements of array is: %d\n",sum);
}