// WAP to convert infix expression to postfix expression
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stack{
    int top;
    char arr[20];
}stack;
int isFull(stack* s){
    return (s->top==sizeof(s->arr)/sizeof(s->arr[0])-1);
}
int isEmpty(stack *s){
    return (s->top==-1);
}
void push(stack *s,char ch){
    if(isFull(s)){
        return;
    }
    s->arr[++s->top]=ch;
}
char pop(stack *s){
    if(isEmpty(s)){
        return '\0';
    }
    return s->arr[s->top--];
}
char peek(stack *s){
    if(isEmpty(s)){
        return '0';
    }
    return s->arr[s->top];
}
int priority(char ch){
    if(ch=='+' || ch=='-'){
        return 1;
    }
    if(ch=='*' || ch=='/'){
        return 2;
    }
    if(ch=='^'){
        return 3;
    }
    return 0;
}
void toPostfix(char exp[],stack *s){
    char org[20];
    strcpy(org,exp);
    int len=strlen(exp);
    int i,j;
    for(i=0,j=0;i<len;i++){
        if(org[i]>=48 && org[i]<=57){
            exp[j++]=org[i];
        }
        else if(org[i]=='+' || org[i]=='-' || org[i]=='*' || org[i]=='/' || org[i]=='^'){
            if(isEmpty(s) || priority(org[i])>priority(peek(s))){
                push(s,org[i]);
            }
            else{
                while(priority(org[i])<=priority(peek(s))){
                    exp[j++]=pop(s);
                }
                push(s,org[i]);
            }
        }
    }
    while((!isEmpty(s))){
        exp[j++]=pop(s);
    }
}
void main(){
    stack *s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    char exp[20];
    printf("Enter an infix expression: ");
    scanf("%s",exp);
    toPostfix(exp,s);
    printf("Equivalent Postfix expression is: %s\n",exp);
    free(s);
}