// WAP to find GCD of two numbers using recursion
#include <stdio.h>
int gcd(int,int);
void main(){
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);
    int max=a>b?a:b;
    int min=a<b?a:b;
    printf("Greatest common divisor of %d and %d is: %d\n",a,b,gcd(max,min));
}
int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    return gcd(b,(a%b));
}