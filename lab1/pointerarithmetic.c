/* prefix operator first updates variable then used in expression
 * postfix operator first uses variable in expression then updates it 
 */
#include <stdio.h>
void main()
{
    char ch='A';
    char *ptr=&ch;
    printf("Initial address: %p\n",ptr);
    printf("After preincrement: %p\n",++ptr);    
    printf("After predecrement: %p\n",--ptr);
    printf("After postincrement: %p\n",ptr++);    
    printf("After postdecrement: %p\n",ptr--);        
    printf("Final address: %p\n",ptr);
}