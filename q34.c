// WAP to evaluate an expression in postfix notation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct stack{
    int top;
    int array[10];
}stack;
int isEmpty(stack *s){
    return s->top==-1;
}
int isFull(stack *s){
    return s->top==(sizeof(s->array)/sizeof(s->array[0])-1);
}
void push(stack *s,int value){
    if(isFull(s)){
        printf("Stack is full\n");
    }
    else{
        s->array[++s->top]=value;
    }
}
int pop(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        return s->array[s->top--];
    }
}
int operate(int a,int b,char ch){
    switch(ch){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        case '^':
            return pow(a,b); 
    }
}
int evaluate(char exp[],stack *s){
    int result;
    int len=strlen(exp);
    for(int i=0;i<len;i++){
        if(exp[i]>=48 && exp[i]<=57){
            push(s,exp[i]-48);
        }
        else{
            int a,b;
            b=pop(s);
            a=pop(s);
            push(s,operate(a,b,exp[i]));
        }
    }
    result=pop(s);
    return result;
}
void main(){
    stack *s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    char exp[20];
    printf("Enter a postfix expression: ");
    scanf("%s",exp);
    int result=evaluate(exp,s);
    printf("Result of given postfix expression is: %d\n",result);
    free(s);
}