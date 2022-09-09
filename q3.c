#include <stdio.h>
void main()
{
    int a=10;
    int* p=&a;
    int** pp=&p;
    printf("%p\n",*pp);
}