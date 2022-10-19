// WAP to implement stack using array, write functions for its operations
#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int top;
    int value[100];
}stack;
int isFull(stack *s){
    if(s->top==(sizeof(s->value)/sizeof(s->value[0])-1)){
        return 1;
    }
    return 0;
}
int isEmpty(stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
void push(stack *s,int data){
    if(isFull(s)){
        printf("Stack full\n");
        return;
    }
    else{
        s->top++;
        s->value[s->top]=data;
    }
}
int pop(stack *s){
    int temp;
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    else if(s->top==0){
        temp=s->value[s->top];
        s->top=-1;
        return temp;
    }
    else{
        temp=s->value[s->top];
        s->top--;
        return temp;
    }
}
int peek(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    return s->value[s->top];
}
void print(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }
    printf("Elements in stack are: ");
    for(int i=0;i<=s->top;i++){
        printf("%d ",s->value[i]);
    }
    printf("\n");
}
void main(){
    stack *s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    push(s,5);
    push(s,3);
    printf("Value at top of stack is: %d\n",peek(s));
    pop(s);
    push(s,9);
    print(s);
    free(s);
}