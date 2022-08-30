#include <stdio.h>
void main()
{
    int a=5,b=10;
    int *ptr=&a;
    printf("%p\t",ptr);
    ptr=&b;
    printf("%p\n",ptr);
}