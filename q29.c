// WAP to find GCD of two numbers using recursion
#include<stdio.h>    
void fibonacci(int);
void main(){    
    int n;    
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Fibonacci Series: ");
    printf("0 1 ");
    fibonacci(n-2);
    printf("\n");
}
void fibonacci(int n){
    static int a=0,b=1,c;
    if(n>0){
        c = a + b;
        a = b;
        b = c;
        printf("%d ",c);
        fibonacci(n-1);   
    }    
}