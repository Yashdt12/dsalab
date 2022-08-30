#include <stdio.h>
void main()
{
    int a,b;
    int *pa=&a,*pb=&b;
    printf("%p\t%p\n",&a,&b);
    printf("%p\t%p\n",pa,pb);
}