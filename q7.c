#include <stdio.h>
void main()
{
    int arr[]={1,2,3,4,5,6},size=6;
    int *start=arr,*end=arr+size-1;
    while(start<=end)
    {
        start++;
        end--;
    }
    if(start==end)
        printf("Middle element is: %d\n",(*start));
    else
        printf("Middle elements are: %d %d\n",(*end),(*start));
}