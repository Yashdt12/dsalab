#include <stdio.h>
void main()
{
    int arr[]={1,2,3,4,5};
    int* ptr=(arr+4);
    for(int i=0;i<5;i++)
    {
        printf("%d\t",(*ptr));
        ptr--;
    }           
    printf("\n");
}