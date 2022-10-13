// WAP to implement multiplication of two numbers using recursion
#include <stdio.h>
int multiply(int,int);
void main(){
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);
    printf("Product of %d and %d is: %d\n",a,b,multiply(a,b));
}
int multiply(int a,int b){
    if(b>0){
        return a+multiply(a,b-1);
    }
    else{
        return 0;
    }
}