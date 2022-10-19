// WAP to check if number is palindrome or not using recursion
#include <stdio.h>
int palindrome(int);
void main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int p=palindrome(n);
    if(n==p){
        printf("Number is a palindrome\n");
    }
    else{
        printf("Number is not a palindrome\n");
    }
}
int palindrome(int n){
    static int sum=0;
    int d;
    if(n!=0){
        d=n%10;
        sum=sum*10+d;
        return palindrome(n/10);
    }
    return sum;
}