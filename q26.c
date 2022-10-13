// WAP to implement factorial using recursion
#include <stdio.h>
int fact(int);
void main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Factorial of %d is: %d\n",n,fact(n));
}
int fact(int n){
    if(n>1){
        return n*fact(n-1);
    }
    else if(n==1){
        return 1;
    }
    else{
        printf("Invalid number\n");
    }
}