// WAP to print Fibonacci series using recursion
#include <stdio.h>
int fibonacci(int);
void main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    fibonacci(n);
    printf("\n");
}
int fibonacci(int n){
    if(n<3){
        printf("0 1 ");
    }
    else{
        printf("%d ",fibonacci(n-1)+fibonacci(n-2));
    }
}